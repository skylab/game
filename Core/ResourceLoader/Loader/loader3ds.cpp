#include "loader3ds.h"

#include "../../Libs/lib3ds/lib3ds.h"
#include "../../Infra/utils.h"

Loader3ds::Loader3ds()
{
    ;
}

Loader3ds::~Loader3ds()
{
    ;
}

bool Loader3ds::Load(const char *filename, Object *object)
{
    Lib3dsFile *file = lib3ds_file_open(filename);
    if (nullptr == file)
    {
        std::cerr << "Can't open file: " << filename << std::endl;
        return false;
    }

    Object *parent = object;
    Lib3dsMesh * model = nullptr;

    for (int meshCnt = 0; meshCnt < file->nmeshes; ++meshCnt)
    {
        model = file->meshes[meshCnt];

        // Face is triangle. We have 3 indev from vertex array about triangle
        object->SetVertexQuantity(model->nfaces * 3);

        // Load all triangles
        glm::vec3 *modelVertexes = *(object->GetVertexArray());
        glm::vec3 *modelUV = *(object->GetUVArray());

        // Count vertex in curent obect
        unsigned int vertexCounter = 0;
        for (unsigned int faceCnt = 0; faceCnt < model->nfaces; ++faceCnt)
        {
            Lib3dsFace *face = &(model->faces[faceCnt]);

            // Load material in case of abcense in TextureManager
            if ( nullptr == TextureManager::Instance()->GetTexture( (GetFilePath(filename)+file->materials[face->material]->texture1_map.name).c_str() ))
            {
                //std::cerr << "Loading: " << file->materials[face->material]->texture1_map.name << std::endl;
                if (nullptr == TextureManager::Instance()->LoadTexture((GetFilePath(filename)+file->materials[face->material]->texture1_map.name).c_str()))
                {
                    std::cerr << __PRETTY_FUNCTION__ << ": Can't load texture" << std::endl;
                }
            }

            Texture *texture = TextureManager::Instance()->GetTexture( (GetFilePath(filename)+file->materials[face->material]->texture1_map.name).c_str() );
            object->AddTexture(texture);

            // Each face have 3 vertexes. Each vertex have 3 point (x,y,z) each point has UV coordinates
            for (unsigned int facePointCnt = 0; facePointCnt < 3; ++facePointCnt)
            {
                float x = model->vertices[face->index[facePointCnt]][0];
                float y = model->vertices[face->index[facePointCnt]][2]; // In the 3ds file "Y" and "Z" axis is swapped
                float z = model->vertices[face->index[facePointCnt]][1];

                //std::cerr << x << " " << y << " " << z << std::endl;

                // Loading UV coordinates
                float u = model->texcos[face->index[facePointCnt]][0];
                float v = model->texcos[face->index[facePointCnt]][1];

                Texture *texture = TextureManager::Instance()->GetTexture((GetFilePath(filename)+file->materials[face->material]->texture1_map.name).c_str());
                float w = object->GetTextureNumberInObject(texture);

                modelUV[vertexCounter] = glm::vec3(u, v, w);

                //std::cerr << u << " " << v << " " << w << std::endl;

                modelVertexes[vertexCounter++] = glm::vec3(x, y, z);
            }
        }

        //std::cerr << "######" << std::endl;

        // In case when file contain more than 1 mesh - add derived object
        if ((meshCnt + 1) < file->nmeshes)
        {
            try
            {
                object = new Object();
            }
            catch(std::bad_alloc &ba)
            {
                std::cerr << __PRETTY_FUNCTION__ << " : " << ba.what() << " : Can't allocate derived object" << std::endl;
                break;
            }
            parent->AddDerivedObject(object);
        }
    }
    lib3ds_file_free(file);
    return true;
}

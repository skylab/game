#include "loader3ds.h"

#include "3ds/lib3ds.h"

Loader3ds::Loader3ds()
{
    ;
}

bool Loader3ds::LoadObjectFile(const char *filename, Object *object)
{
    Lib3dsFile *file = lib3ds_file_open(filename);
    if (nullptr == file)
    {
        std::cerr << "Can't open file: " << filename << std::endl;
        return false;
    }

    Object *parent = object;

    Lib3dsMesh * model = nullptr;

    //std::cerr << "Mesh count: " << file->nmeshes << std::endl;

    for (unsigned int meshCnt = 0; meshCnt < file->nmeshes; ++meshCnt)
    {
        model = file->meshes[meshCnt];

        // Count vertex in curent obect
        unsigned int vertexCounter = 0;

        // Face is triangle. We have 3 indev from vertex array about triangle
        object->SetObjectVertexQuantity(model->nfaces * 3);

        // Load all triangles
        for (unsigned int faceCnt = 0; faceCnt < model->nfaces; ++faceCnt)
        {
            Lib3dsFace face = model->faces[faceCnt];

            // Each face have 3 vertexes. Each vertex have 3 point (x,y,z)
            for (unsigned int facePointCnt = 0; facePointCnt < 3; ++facePointCnt)
            {
                float x = model->vertices[face.index[facePointCnt]][0];
                float y = model->vertices[face.index[facePointCnt]][2]; // In the 3ds file "Y" and "Z" axis is swapped
                float z = model->vertices[face.index[facePointCnt]][1];

                object->GetObjectVertexes()[vertexCounter++] = glm::vec3(x, y, z);
            }
        }

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
            // Assign new object to parent.
            parent->AddDerivedObject(object);
        }
    }
    lib3ds_file_free(file);
    return true;
}

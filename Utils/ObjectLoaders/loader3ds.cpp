#include "loader3ds.h"

#include "3ds/lib3ds.h"

Loader3ds::Loader3ds()
{
    ;
}

bool Loader3ds::LoadObjectFile(const char *filename, ObjectRaw *object)
{
    Lib3dsFile *file = lib3ds_file_open(filename);
    if (nullptr == file)
    {
        std::cerr << "Can't open file: " << filename << std::endl;
        return false;
    }

    Lib3dsMesh * model = nullptr;

    for (unsigned int meshCnt = 0; meshCnt < 1 /*file->nmeshes*/; ++meshCnt)
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
    }
    lib3ds_file_free(file);
    return true;
}

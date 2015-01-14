#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "../Infra/singleton.h"
#include "../ObjectLevels/object.h"

class ModelLoader : public Singleton<ModelLoader>
{
public:
    ModelLoader();
    virtual ~ModelLoader();

    const char *GetName(void) const override;

    bool LoadModelFile(const char *filename, Object *object);
};

#endif // MODELLOADER_H

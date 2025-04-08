#include <SofaSphFluid/OglFluidModel.inl>

#include <sofa/core/ObjectFactory.h>


namespace sofa::component::visualmodel
{

SOFA_DECL_CLASS(OglFluidModel)

void registerOglFluidModel(sofa::core::ObjectFactory* factory)
{
    factory->registerObjects(sofa::core::ObjectRegistrationData("Particle model for OpenGL display, using glsl.")
    .add< OglFluidModel<sofa::defaulttype::Vec3Types> >());
}

template class SOFA_SPH_FLUID_API OglFluidModel<sofa::defaulttype::Vec3Types>;

}



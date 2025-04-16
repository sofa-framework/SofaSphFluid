/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <SofaSphFluid/config.h>

#include <sofa/core/ObjectFactory.h>
#include <sofa/helper/system/PluginManager.h>


namespace sofa::component::misc
{
    extern void registerParticleSink(sofa::core::ObjectFactory* factory);
    extern void registerParticleSource(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::collision
{
    extern void registerSpatialGridPointModel(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::container
{
    extern void registerSpatialGridContainer(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::forcefield
{
    extern void registerParticlesRepulsionForceField(sofa::core::ObjectFactory* factory);
    extern void registerSPHFluidForceField(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::mapping
{
    extern void registerSPHFluidSurfaceMapping(sofa::core::ObjectFactory* factory);
}
namespace sofa::component::visualmodel
{
    extern void registerOglFluidModel(sofa::core::ObjectFactory* factory);
}


namespace sofasphfluid
{

extern "C" {
SOFA_SPH_FLUID_API void initExternalModule();
SOFA_SPH_FLUID_API const char* getModuleName();
SOFA_SPH_FLUID_API const char* getModuleVersion();
SOFA_SPH_FLUID_API const char* getModuleLicense();
SOFA_SPH_FLUID_API const char* getModuleDescription();
SOFA_SPH_FLUID_API void registerObjects(sofa::core::ObjectFactory* factory);
}

void initExternalModule()
{
    static bool first = true;
    if (first)
    {
        // make sure that this plugin is registered into the PluginManager
        sofa::helper::system::PluginManager::getInstance().registerPlugin(MODULE_NAME);

        first = false;
    }
}

const char* getModuleName()
{
    return MODULE_NAME;
}

const char* getModuleVersion()
{
    return MODULE_VERSION;
}

const char* getModuleLicense()
{
    return "LGPL";
}

const char* getModuleDescription()
{
    return "This plugin contains fluids simulation based on the SPH method.";
}

void registerObjects(sofa::core::ObjectFactory* factory)
{
    sofa::component::misc::registerParticleSink(factory);
    sofa::component::misc::registerParticleSource( factory);
    sofa::component::collision::registerSpatialGridPointModel(factory);
    sofa::component::container::registerSpatialGridContainer(factory);
    sofa::component::forcefield::registerParticlesRepulsionForceField(factory);
    sofa::component::forcefield::registerSPHFluidForceField(factory);
    sofa::component::mapping::registerSPHFluidSurfaceMapping(factory);
    sofa::component::visualmodel::registerOglFluidModel(factory);
}

} // namespace sofasphfluid



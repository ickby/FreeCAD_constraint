/***************************************************************************
 *   Copyright (c) 2010 Juergen Riegel <FreeCAD@juergen-riegel.net>        *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef Assembly_Item_H
#define Assembly_Item_H

#include <App/PropertyStandard.h>
#include <Mod/Part/App/PartFeature.h>


namespace Assembly
{

class AssemblyExport Item : public Part::Feature
{
    PROPERTY_HEADER(Assembly::Item);

public:
    Item();

   /** @name base properties of all Assembly Items */
    //@{
    /// Id e.g. Part number
    App::PropertyString  Id;
    /// unique identifier of the Item 
    App::PropertyUUID    Uid;
    /// Name of the Item (human readable)
    App::PropertyString  Name  ;
    /// long description of the Item 
    App::PropertyString  Description  ;
    //@}

    /** @name base properties of all Assembly Items */
    //@{
    /** Base color of the Item
        If the transparency value is 1.0
        the color or the next hirachy is used
        */
    App::PropertyColor Color;
    /// Visibility
    App::PropertyBool  Visibility;
    //@}

    /** @name methods override feature */
    //@{
    /// recalculate the feature
    App::DocumentObjectExecReturn *execute(void);
    short mustExecute() const;
    /// returns the type name of the view provider
    const char* getViewProviderName(void) const {
        return "AssemblyGui::ViewProviderItem";
    }
    //@}
};

} //namespace PartDesign


#endif // PART_Item_H
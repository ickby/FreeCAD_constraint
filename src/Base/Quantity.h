/***************************************************************************
 *   Copyright (c) 2013 Juergen Riegel                                     *
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


#ifndef BASE_Quantity_H
#define BASE_Quantity_H

#include "Unit.h"

namespace Base {

/**
 * The Quantity class.
 */
class BaseExport Quantity
{
public:
    /// default constructor
    Quantity(void);
    Quantity(const Quantity&);
    Quantity(double Value, const Unit& unit=Unit());
    /// Destruction
    ~Quantity () {};

    /** Operators. */
    //@{
    Quantity operator *(const Quantity &p) const;
    Quantity operator +(const Quantity &p) const;
    Quantity operator -(const Quantity &p) const;
    Quantity operator -(void) const;
    Quantity operator /(const Quantity &p) const;
    bool operator ==(const Quantity&) const;
    Quantity& operator =(const Quantity&);
    Quantity pow(const Quantity&)const;
    //@}

protected:
    double _Value;
    Unit   _Unit;

    static Quantity parse(const char* buffer);
};

} // namespace Base

#endif // BASE_Quantity_H

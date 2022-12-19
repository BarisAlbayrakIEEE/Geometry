// GeometryLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

// TODO: This is an example of a library function
void fnGeometryLibrary()
{
}

/*
#include <string>
#include <iostream>

#include "CoordSystem.hxx"
#include "GlobalCoordSystem.hxx"
#include "PointBase.hxx"
#include "Point2D.hxx"
#include "Point3D.hxx"
#include "VectorBase.hxx"
#include "Vector2D.hxx"
#include "Vector3D.hxx"
#include "Axis.hxx"
#include "Line.hxx"
#include "Circle.hxx"
#include "Plane.hxx"
#include "Macros.h"
//#include "GeometryFactory.hxx"

using namespace GeometryNamespace;

int main()
{
    //std::cout << "Hello World!\n";
    std::string pn = "p1";
    arrayS3 pc1{ 11., 21., 0. };
    arrayS3 pc2{ 12., 22., 0. };
    arrayS3 pc3{ 13., 24., 0. };
    Handle(Point3D) p1 { Handle(Point3D)(new Point3D(pc1)) };
    Handle(Point3D) p2 { Handle(Point3D)(new Point3D(pc2)) };
    Handle(Point3D) p3 { Handle(Point3D)(new Point3D(pc3)) };
    //Handle(CoordSystem) fp1 = GeometryFactory::createCoordSystem(pn, p1, p2, p3);
    Handle(Axis) il1 { Handle(Axis)(new Axis(p1, p2)) };
    Handle(Axis) il2 { il1 };
    Axis il3{ Axis(p1, p2) };
    Axis il4{ il3 };
    std::cout << p1->getReferenceCoordSystem()->getOriginCoords()[0] << "\n";
    std::cout << p1->getReferenceCoordSystem()->getName() << "\n";
}
*/

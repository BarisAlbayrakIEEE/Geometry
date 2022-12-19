/// <summary>
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#include <iostream>
#include <Macros.h>
#include <GeometryAbstractObject.hxx>
#include <GeometryObject.hxx>
#include <GeometryParameters.hxx>
#include <CoordSystem.hxx>
#include <GlobalCoordSystem.hxx>
#include <Point2D.hxx>
#include <Point3D.hxx>
#include <Vector2D.hxx>
#include <Vector3D.hxx>
#include <Axis.hxx>
#include <Line.hxx>
#include <Circle.hxx>
#include <Plane.hxx>

using namespace GeometryNamespace;

int main()
{
    Handle(Point3D) point1 { new Point3D(arrayS3{ 11., 12., 13. }) };
    Handle(Point3D) point2 { new Point3D(arrayS3{ 24., 25., 21. }) };
    Handle(Point3D) point3 { new Point3D(arrayS3{ 35., 39., 32. }) };
    Handle(CoordSystem) CS1 { new CoordSystem(point1, point2, point3) };
    std::cout << "point1->getLocalCoordX(): " << point1->getLocalCoordX() << "\n";
    std::cout << "point1->getGlobalCoordX(): " << point1->getGlobalCoordX() << "\n";
    std::cout << "CS1->getAxisComponentsX()[0]: " << CS1->getAxisComponentsX()[0] << "\n";
    std::cout << "CS1->getAxisComponentsY()[0]: " << CS1->getAxisComponentsY()[0] << "\n";

    Handle(Point3D) point4 { new Point3D(CS1, arrayS3{ 11., 12., 13. }) };
    Handle(Point3D) point5 { new Point3D(CS1, arrayS3{ 24., 25., 21. }) };
    std::cout << "point4->getLocalCoordX(): " << point4->getLocalCoordX() << "\n";
    std::cout << "point4->getGlobalCoordX(): " << point4->getGlobalCoordX() << "\n";

    Handle(VectorBase) vector1 { VectorBase::createUnitVectorX(DIMENSIONS::D2, CS1) };
    Handle(Vector2D) vector2 { Handle(Vector2D)::DownCast(VectorBase::createUnitVectorX(DIMENSIONS::D2, CS1)) };
    Handle(Vector3D) vector3 { Handle(Vector3D)::DownCast(VectorBase::createUnitVectorX(DIMENSIONS::D3, CS1)) };
    Handle(Vector3D) vector4 { new Vector3D(point1, point2) };
    Handle(Vector3D) vector5 { new Vector3D(point4, point5) };
    std::cout << "vector1->getLocalComponentX(): " << vector1->getLocalComponentX() << "\n";
    std::cout << "vector1->getGlobalComponentX(): " << vector1->getGlobalComponentX() << "\n";
    std::cout << "vector2->getLocalComponentX(): " << vector2->getLocalComponentX() << "\n";
    std::cout << "vector2->getGlobalComponentX(): " << vector2->getGlobalComponentX() << "\n";
    std::cout << "vector3->getLocalComponentX(): " << vector3->getLocalComponentX() << "\n";
    std::cout << "vector3->getGlobalComponentX(): " << vector3->getGlobalComponentX() << "\n";
    std::cout << "vector4->getLocalComponentX(): " << vector4->getLocalComponentX() << "\n";
    std::cout << "vector4->getGlobalComponentX(): " << vector4->getGlobalComponentX() << "\n";
    std::cout << "vector5->getLocalComponentX(): " << vector5->getLocalComponentX() << "\n";
    std::cout << "vector5->getGlobalComponentX(): " << vector5->getGlobalComponentX() << "\n";
    std::cout << "vector1->getMagnitude(): " << vector1->getMagnitude() << "\n";
    std::cout << "vector2->getMagnitude(): " << vector2->getMagnitude() << "\n";
    std::cout << "vector3->getMagnitude(): " << vector3->getMagnitude() << "\n";
    std::cout << "vector4->getMagnitude(): " << vector4->getMagnitude() << "\n";
    std::cout << "vector5->getMagnitude(): " << vector5->getMagnitude() << "\n";

    Handle(Line) line1 { new Line(point1, point2) };
    std::cout << "line1->getDirectionVector()->getLocalComponentX(): " << line1->getDirectionVector()->getLocalComponentX() << "\n";
    std::cout << "line1->getLength(): " << line1->getLength() << "\n";

    Handle(Axis) axis1 { new Axis(point1, vector3) };
    std::cout << "axis1->getPassingPoint()->getGlobalCoordX(): " << axis1->getPassingPoint()->getGlobalCoordX() << "\n";
    std::cout << "axis1->getDirectionVector()->getLocalComponentX(): " << axis1->getDirectionVector()->getLocalComponentX() << "\n";

    bool includes1{ line1->includes(point1) };
    bool includes2{ line1->includes(point2) };
    bool includes3{ line1->includes(point3) };
    bool includes4{ axis1->includes(point1) };
    bool includes5{ axis1->includes(point2) };
    bool includes6{ axis1->includes(point3) };
    bool intersects{ axis1->intersects(line1) };
    std::pair<INTERSECTION1, Handle(PointBase)> intersection{ axis1->intersect(line1) };
    std::cout << "includes1: " << includes1 << "\n";
    std::cout << "includes2: " << includes2 << "\n";
    std::cout << "includes3: " << includes3 << "\n";
    std::cout << "includes4: " << includes4 << "\n";
    std::cout << "includes5: " << includes5 << "\n";
    std::cout << "includes6: " << includes6 << "\n";
    std::cout << "intersection.first: " << intersection.first << "\n";
    std::cout << "intersection.second.IsNull(): " << intersection.second.IsNull() << "\n";
}

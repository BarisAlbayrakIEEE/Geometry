# GeometryLibrary

/// <summary>
/// An OCCT embedded library for a simple implementation of the geometry objects (e.g. point, vector and circle)
/// CAUTION:
///     Opencascade Technology (OCCT) library shall be embedded to use this library:
///         Download: https://www.opencascade.com/
///         How to: https://www.youtube.com/watch?v=i5zCHArA06E
///     See GeometryAPI project in my repository which can be used as the interface of this library.
/// 
/// This library is a simple implementation for the geometry objects (e.g. point, vector and circle)
/// and interactions of these objects.
/// Complex geometries (e.g. a geometrically undefined surface) are not included yet.
/// 
/// The geometry basically defined wrt to coordinate systems (CSs) in order to
///   1. simplify the tracebility of the objects
///   2. switch between spaces, especially 3D to 2D (or 2D to 3D)
/// The 1st functionality is a fundamental issue in engineering applications.
/// For example, an assembly of bodies is defined in a global CS
/// while each body has its own CS.
/// The 2nd functionality is similar to the 1st one.
/// Its benefit is more clear when it comes to switching between 2D and 3D spaces.
/// All CAE software (e.g. Catia) supports switching to 2D space.
/// This library can be utilized in this respect.
/// 
/// The z dimension (i.e. coord for a point and component for a vector) is zero for 2D objects by defaullt.
/// However, the object does not have to be defined wrt the global CS.
/// If a CS other than the global CS is defined as the reference CS of a 2D object,
/// the object has x and y dimensions but no z-dimension wrt that CS.
/// 
/// Reference CS to global CS (or vice versa) transformations are supported.
/// 
/// Global CS is a singleton class.
/// See GlobalCoordSystem.hxx for the details
/// 
/// Axis, Line, Circle and Plane classes inherit from the base class (GeometryObject)
/// and do not have 2D and 3D types (e.g. Axis2D).
/// Actually, only the classes inheritting from ReferenceObject have 2D and 3D types.
/// The problem is not 2D/3D types but the reference CS.
/// An Axis cannot have a reference CS
/// because it has two members (point and vector)
/// and the reference CSs of the two may not be the same.
/// This can be satisfied as a precondition in the ctors of Axis
/// but the reference CSs of the point and vector members can be modified
/// after the Axis object instantiation.
/// Hence, setReferenceCoordSystem method of ReferenceObject shall be removed
/// in order for Axis to have a reference CS
/// But this solution is not preferable.
/// Hence, the types with more than one ReferenceObject members (Axis, Line, Circle and Plane)
/// do not have a reference CS and 2D/3D types
/// and inherit from the root class (GeometryObject).
/// Instead, they have three member functions:
/// is2D, is3D and getCommonReferenceCoordSystem
/// 
/// The objects in the library are defined in an implementation hyerarchy.
/// The slicing problem that comes with the inheritance is
/// solved by deleting the copy/move ctors and operators.
/// Hence, copy/move ctors and aassignments of all base classes accept for PointBase
/// (GeometryObject, ReferenceObject, CoordSystem, VectorBase) are deleted.
/// Point2D and Point3D classes do not have additional members
/// so that the slicing issue is not a problem for them.
/// 
/// Additionally, OCCT handle class copy operations create new pointer to the existing object.
/// In other words, copy ctor of OCCT handle class creates a shallow copy of the pointed object.
/// However, the classes in this library implements deep copy in copy/move ctors and assignment operators.
/// For example, copy ctor of Axis class creates new Point and Vector objects
/// as the application point and the direction vector.
/// Hence, use the copy/move ctor and operator of the library class if a deep copy needed.
/// Ex:
///		Handle(T) obj1;
///		Handle(T) obj2 = Handle(T)(obj1); // Shallow copy
///		Handle(T) obj3 = Handle(T)(new T(obj1.get())); // Deep copy
///		Handle(T) obj4 = new T(obj1.get()); // Deep copy, uses copy ctor of library class and handle's copy assignment by pointer
///		Handle(T) obj5 = obj1.copy(); // Deep copy, uses copy member method of library class
/// 
/// The tolerance members (c_toleranceGeneral and c_toleranceSensitive)
/// are crutial due to two reasons:
///     1. To eliminate any kind of computational errors (e.g. truncation errors),
///     2. To be able to perform approximate calculations.
///        For example, intersection of two line may not exist theoritically
///        but an approximate point can be found.
///        A tolerance value is required for such approximations.
/// In the library, all inspections for the equality contains a tolerance value
/// using GeometryMath::equals method.
/// There exist two kind of tolerance value:
///     1. c_toleranceGeneral: General purpose tolerance value
///     2. c_toleranceSensitive: Used for sensitive calculations
/// As an example, c_toleranceGeneral is used in the distance calculations.
/// c_toleranceSensitive is used in angle calculations as angle values are too small when working with radians.
/// Users can set the values of the tolerance members of the objects of this library anytime required.
/// 
/// author: baris.albayrak.ieee@gmail.com
/// </summary>

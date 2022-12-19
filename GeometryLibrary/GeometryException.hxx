/// <summary>
/// Exceptions defined for the GeometryNamespace
/// 
/// CAUTION:
///     Opencascade Technology (OCCT) library shall be embedded to use this library:
///         Download: https://www.opencascade.com/
///         How to: https://www.youtube.com/watch?v=i5zCHArA06E
///     See GeometrySample project in my repository for sample usage of the libraries.
/// 
/// See GeometryObject.hxx for project definition and main descriptions.
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>


#ifndef _GeometryException_hxx_
#define _GeometryException_hxx_

#include <iostream>
using namespace std;

namespace GeometryNamespace {
	class GeometryException : public std::exception
	{
	public:
		char const* what() const
		{
			return "TBD";
		}
	};

	class UncaughtException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Uncaught Exception";
		}
	};

	class AlreadyExistingObjectException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "An object with the input name aalready exists.";
		}
	};

	class ObjectTypeException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "The type of the object does not math the type of the requested object.";
		}
	};

	class NullptrException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Null pointer for an input.";
		}
	};

	class BadInputException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Bad data for an input.";
		}
	};

	class DivideByZeraException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Division by zero";
		}
	};

	class ZeroToleranceException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "The tolerance value set less than or equal to zero which must be positive real value.";
		}
	};

	class ZeroDeterminantException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Determinant of the matrix is zerom. Inverse matrix does not exist.";
		}
	};

	class ArraySizeException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Array size is zero ar not same as the expected";
		}
	};

	class MaxIterationReachedException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "No solution. Max iteration has reached.";
		}
	};

	class DimensionalityException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "The dimensionality of the instance is not suitable for the requested operation.";
		}
	};

	class ZeroDimensionException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "The instance is defined in 2D space.";
		}
	};

	class GeometricalMismatchException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Two or more entities in the operation do not match (e.g. a point does not lie on the plane or non-perpandicular vectors for a CS).";
		}
	};

	class CoordSystemMismatchException : public GeometricalMismatchException
	{
	public:
		char const* what() const
		{
			return "Reference CSs are not the same.";
		}
	};

	class NoIntersectionException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "No intersection between the two components.";
		}
	};

	class ZeroVectorException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Vector magnitude is zero. nullptr vector";
		}
	};

	class CoincidenceException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Coincident items";
		}
	};

	class ColinearPointsException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Points are colinear.";
		}
	};

	class ParallelAxisException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "Axes are parallel.";
		}
	};

	class AssymptoticLineException : public GeometryException
	{
	public:
		char const* what() const
		{
			return "The line is parallel to one of the axes.";
		}
	};
}

#endif

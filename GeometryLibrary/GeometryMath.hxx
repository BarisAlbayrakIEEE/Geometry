/// <summary>
/// Includes some simple math functions.
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

#ifndef _GeometryMath_hxx_
#define _GeometryMath_hxx_

#ifndef _Macros_HeaderFile
#include "Macros.h"
#endif
#ifndef _GeometryException_HeaderFile
#include "GeometryException.hxx"
#endif
#ifndef _GeometryParameters_HeaderFile
#include "GeometryParameters.hxx"
#endif

namespace GeometryNamespace {
	struct GeometryMath
	{
	public:
		static double interpolate(double theValueO, double theValue1, double theFactor);
		static bool equals(double theValueO, double theValue1, double theTolerance);
		static bool equals(arrayS2 theValues0, arrayS2 theValues1, double theTolerance);
		static bool equals(arrayS3 theValues0, arrayS3 theValues1, double theTolerance);
		static bool equals(arrayS4 theValues0, arrayS4 theValues1, double theTolerance);
		static bool equals(arrayS32 theValues0, arrayS32 theValues1, double theTolerance);
		static bool equals(arrayS33 theValues0, arrayS33 theValues1, double theTolerance);
		static bool equalsZero(arrayS2 theValues0, double theTolerance);
		static bool equalsZero(arrayS3 theValues0, double theTolerance);
		static bool equalsZero(arrayS4 theValues0, double theTolerance);
		static bool equalsZero(arrayS32 theValues0, double theTolerance);
		static bool equalsZero(arrayS33 theValues0, double theTolerance);
		static arrayS2 copyArray(arrayS2 theValues);
		static arrayS3 copyArray(arrayS3 theValues);
		static arrayS4 copyArray(arrayS4 theValues);
		static arrayS32 copyArray(arrayS32 theValues);
		static arrayS33 copyArray(arrayS33 theValues);
		static arrayS3 convertArrayS2ToS3(arrayS2 theValues);
		static arrayS2 factorizeArray(arrayS2 theValues, double theFactor);
		static arrayS3 factorizeArray(arrayS3 theValues, double theFactor);
		static arrayS4 factorizeArray(arrayS4 theValues, double theFactor);
		static arrayS32 factorizeArray(arrayS32 theValues, double theFactor);
		static arrayS33 factorizeArray(arrayS33 theValues, double theFactor);
		static arrayS2 sumArrays(arrayS2 theValues0, arrayS2 theValues1);
		static arrayS3 sumArrays(arrayS3 theValues0, arrayS3 theValues1);
		static arrayS4 sumArrays(arrayS4 theValues0, arrayS4 theValues1);
		static arrayS32 sumArrays(arrayS32 theValues0, arrayS32 theValues1);
		static arrayS33 sumArrays(arrayS33 theValues0, arrayS33 theValues1);
		static arrayS2 subtructArrays(arrayS2 theValues0, arrayS2 theValues1);
		static arrayS3 subtructArrays(arrayS3 theValues0, arrayS3 theValues1);
		static arrayS4 subtructArrays(arrayS4 theValues0, arrayS4 theValues1);
		static arrayS32 subtructArrays(arrayS32 theValues0, arrayS32 theValues1);
		static arrayS33 subtructArrays(arrayS33 theValues0, arrayS33 theValues1);
		static arrayS2 vectorToArray1DS2(vectorInput1D theValues);
		static arrayS3 vectorToArray1DS3(vectorInput1D theValues);
		static arrayS4 vectorToArray1DS4(vectorInput1D theValues);
		static arrayS32 vectorToArray2DS32(vectorInput2D theValues);
		static arrayS33 vectorToArray2DS33(vectorInput2D theValues);
		static arrayS33 multiplyMatrixToMatrixS3(arrayS33 theValues0, arrayS33 theValues1);
		static arrayS3 multiplyMatrixToVectorS33S3(arrayS33 theValues0, arrayS3 theValues1);
		static double calculateMatrixDeterminantS33(arrayS33 theMatrix);
		static arrayS33 calculateMatrixInverseS33(arrayS33 theMatrix, double theTolerance);
		static double normalizeAngle(const double& theAngle);
	};
};

#endif

// baris.albayrak.ieee@gmail.com

#include "GeometryMath.hxx"

namespace GeometryNamespace {
	/// <summary>
	/// theFactor: Betwen 0. and 1.
	///	Defines how much of the distance between the two values is to be travelled
	/// </summary>
	double GeometryMath::interpolate(double theValue0, double theValue1, double theFactor)
	{
		return theValue0 + (theValue1 - theValue0) * theFactor;
	}

	bool GeometryMath::equals(double theValue0, double theValue1, double theTolerance)
	{
		if (std::fabs(theValue0 - theValue1) < theTolerance) return true;
		return false;
	}

	bool GeometryMath::equals(arrayS2 theValues0, arrayS2 theValues1, double theTolerance)
	{
		for (int i = 0; i < theValues0.size(); ++i) {
			if (!GeometryMath::equals(theValues0[i], theValues1[i], theTolerance)) {
				return false;
			}
		}
		return true;
	}

	bool GeometryMath::equals(arrayS3 theValues0, arrayS3 theValues1, double theTolerance)
	{
		for (int i = 0; i < theValues0.size(); ++i) {
			if (!GeometryMath::equals(theValues0[i], theValues1[i], theTolerance)) {
				return false;
			}
		}
		return true;
	}

	bool GeometryMath::equals(arrayS4 theValues0, arrayS4 theValues1, double theTolerance)
	{
		for (int i = 0; i < theValues0.size(); ++i) {
			if (!GeometryMath::equals(theValues0[i], theValues1[i], theTolerance)) {
				return false;
			}
		}
		return true;
	}

	bool GeometryMath::equals(arrayS32 theValues0, arrayS32 theValues1, double theTolerance)
	{
		for (int i0 = 0; i0 < theValues0.size(); ++i0) {
			for (int i1 = 0; i1 < theValues0[0].size(); ++i1) {
				if (!GeometryMath::equals(theValues0[i0][i1], theValues1[i0][i1], theTolerance)) {
					return false;
				}
			}
		}
		return true;
	}

	bool GeometryMath::equals(arrayS33 theValues0, arrayS33 theValues1, double theTolerance)
	{
		for (int i0 = 0; i0 < theValues0.size(); ++i0) {
			for (int i1 = 0; i1 < theValues0[0].size(); ++i1) {
				if (!GeometryMath::equals(theValues0[i0][i1], theValues1[i0][i1], theTolerance)) {
					return false;
				}
			}
		}
		return true;
	}

	bool GeometryMath::equalsZero(arrayS2 theValues, double theTolerance) {
		for (int i = 0; i < theValues.size(); i++) {
			if (!GeometryMath::equals(theValues[i], 0., theTolerance)) {
				return false;
			}
		}
		return true;
	}

	bool GeometryMath::equalsZero(arrayS3 theValues, double theTolerance) {
		for (int i = 0; i < theValues.size(); i++) {
			if (!GeometryMath::equals(theValues[i], 0., theTolerance)) {
				return false;
			}
		}
		return true;
	}

	bool GeometryMath::equalsZero(arrayS4 theValues, double theTolerance) {
		for (int i = 0; i < theValues.size(); i++) {
			if (!GeometryMath::equals(theValues[i], 0., theTolerance)) {
				return false;
			}
		}
		return true;
	}

	bool GeometryMath::equalsZero(arrayS32 theValues, double theTolerance) {
		for (int i0 = 0; i0 < theValues.size(); ++i0) {
			for (int i1 = 0; i1 < theValues[0].size(); ++i1) {
				if (!GeometryMath::equals(theValues[i0][i1], 0., theTolerance)) {
					return false;
				}
			}
		}
		return true;
	}

	bool GeometryMath::equalsZero(arrayS33 theValues, double theTolerance) {
		for (int i0 = 0; i0 < theValues.size(); ++i0) {
			for (int i1 = 0; i1 < theValues[0].size(); ++i1) {
				if (!GeometryMath::equals(theValues[i0][i1], 0., theTolerance)) {
					return false;
				}
			}
		}
		return true;
	}

	arrayS2 GeometryMath::copyArray(arrayS2 theValues) {
		arrayS2 outValues{ arrayS2{} };
		for (int i = 0; i < theValues.size(); i++) {
			outValues[i] = theValues[i];
		}
		return outValues;
	}

	arrayS3 GeometryMath::copyArray(arrayS3 theValues) {
		arrayS3 outValues{ arrayS3{} };
		for (int i = 0; i < theValues.size(); i++) {
			outValues[i] = theValues[i];
		}
		return outValues;
	}

	arrayS4 GeometryMath::copyArray(arrayS4 theValues) {
		arrayS4 outValues{ arrayS4{} };
		for (int i = 0; i < theValues.size(); i++) {
			outValues[i] = theValues[i];
		}
		return outValues;
	}

	arrayS32 GeometryMath::copyArray(arrayS32 theValues) {
		arrayS32 outValues{ arrayS32{} };
		for (int i0 = 0; i0 < theValues.size(); ++i0) {
			for (int i1 = 0; i1 < theValues[0].size(); ++i1) {
				outValues[i0][i1] = theValues[i0][i1];
			}
		}
		return outValues;
	}

	arrayS33 GeometryMath::copyArray(arrayS33 theValues) {
		arrayS33 outValues{ arrayS33{} };
		for (int i0 = 0; i0 < theValues.size(); ++i0) {
			for (int i1 = 0; i1 < theValues[0].size(); ++i1) {
				outValues[i0][i1] = theValues[i0][i1];
			}
		}
		return outValues;
	}

	arrayS3 GeometryMath::convertArrayS2ToS3(arrayS2 theValues) {
		arrayS3 s3{};
		for (int i = 0; i < DIMENSIONS::D2; ++i)
		{
			s3[i] = theValues[i];
		}
		return s3;
	}

	arrayS2 GeometryMath::factorizeArray(arrayS2 theValues, double theFactor) {
		arrayS2 outValues{ arrayS2{} };
		for (int i = 0; i < theValues.size(); i++) {
			outValues[i] = theFactor * theValues[i];
		}
		return outValues;
	}

	arrayS3 GeometryMath::factorizeArray(arrayS3 theValues, double theFactor) {
		arrayS3 outValues{ arrayS3{} };
		for (int i = 0; i < theValues.size(); i++) {
			outValues[i] = theFactor * theValues[i];
		}
		return outValues;
	}

	arrayS4 GeometryMath::factorizeArray(arrayS4 theValues, double theFactor) {
		arrayS4 outValues{ arrayS4{} };
		for (int i = 0; i < theValues.size(); i++) {
			outValues[i] = theFactor * theValues[i];
		}
		return outValues;
	}

	arrayS32 GeometryMath::factorizeArray(arrayS32 theValues, double theFactor) {
		arrayS32 outValues{ arrayS32{} };
		for (int i0 = 0; i0 < theValues.size(); ++i0) {
			for (int i1 = 0; i1 < theValues[0].size(); ++i1) {
				outValues[i0][i1] = theFactor * theValues[i0][i1];
			}
		}
		return outValues;
	}

	arrayS33 GeometryMath::factorizeArray(arrayS33 theValues, double theFactor) {
		arrayS33 outValues{ arrayS33{} };
		for (int i0 = 0; i0 < theValues.size(); ++i0) {
			for (int i1 = 0; i1 < theValues[0].size(); ++i1) {
				outValues[i0][i1] = theFactor * theValues[i0][i1];
			}
		}
		return outValues;
	}

	arrayS2 GeometryMath::sumArrays(arrayS2 theValues0, arrayS2 theValues1) {
		arrayS2 outValues{ arrayS2{} };
		for (int i = 0; i < theValues0.size(); i++) {
			outValues[i] = theValues0[i] + theValues1[i];
		}
		return outValues;
	}

	arrayS3 GeometryMath::sumArrays(arrayS3 theValues0, arrayS3 theValues1) {
		arrayS3 outValues{ arrayS3{} };
		for (int i = 0; i < theValues0.size(); i++) {
			outValues[i] = theValues0[i] + theValues1[i];
		}
		return outValues;
	}

	arrayS4 GeometryMath::sumArrays(arrayS4 theValues0, arrayS4 theValues1) {
		arrayS4 outValues{ arrayS4{} };
		for (int i = 0; i < theValues0.size(); i++) {
			outValues[i] = theValues0[i] + theValues1[i];
		}
		return outValues;
	}

	arrayS32 GeometryMath::sumArrays(arrayS32 theValues0, arrayS32 theValues1) {
		arrayS32 outValues{ arrayS32{} };
		for (int i0 = 0; i0 < theValues0.size(); ++i0) {
			for (int i1 = 0; i1 < theValues0[0].size(); ++i1) {
				outValues[i0][i1] = theValues0[i0][i1] + theValues1[i0][i1];
			}
		}
		return outValues;
	}

	arrayS33 GeometryMath::sumArrays(arrayS33 theValues0, arrayS33 theValues1) {
		arrayS33 outValues{ arrayS33{} };
		for (int i0 = 0; i0 < theValues0.size(); ++i0) {
			for (int i1 = 0; i1 < theValues0[0].size(); ++i1) {
				outValues[i0][i1] = theValues0[i0][i1] + theValues1[i0][i1];
			}
		}
		return outValues;
	}

	arrayS2 GeometryMath::subtructArrays(arrayS2 theValues0, arrayS2 theValues1) {
		arrayS2 outValues{ arrayS2{} };
		for (int i = 0; i < theValues0.size(); i++) {
			outValues[i] = theValues0[i] - theValues1[i];
		}
		return outValues;
	}

	arrayS3 GeometryMath::subtructArrays(arrayS3 theValues0, arrayS3 theValues1) {
		arrayS3 outValues{ arrayS3{} };
		for (int i = 0; i < theValues0.size(); i++) {
			outValues[i] = theValues0[i] - theValues1[i];
		}
		return outValues;
	}

	arrayS4 GeometryMath::subtructArrays(arrayS4 theValues0, arrayS4 theValues1) {
		arrayS4 outValues{ arrayS4{} };
		for (int i = 0; i < theValues0.size(); i++) {
			outValues[i] = theValues0[i] - theValues1[i];
		}
		return outValues;
	}

	arrayS32 GeometryMath::subtructArrays(arrayS32 theValues0, arrayS32 theValues1) {
		arrayS32 outValues{ arrayS32{} };
		for (int i0 = 0; i0 < theValues0.size(); ++i0) {
			for (int i1 = 0; i1 < theValues0[0].size(); ++i1) {
				outValues[i0][i1] = theValues0[i0][i1] - theValues1[i0][i1];
			}
		}
		return outValues;
	}

	arrayS33 GeometryMath::subtructArrays(arrayS33 theValues0, arrayS33 theValues1) {
		arrayS33 outValues{ arrayS33{} };
		for (int i0 = 0; i0 < theValues0.size(); ++i0) {
			for (int i1 = 0; i1 < theValues0[0].size(); ++i1) {
				outValues[i0][i1] = theValues0[i0][i1] - theValues1[i0][i1];
			}
		}
		return outValues;
	}

	arrayS2 GeometryMath::vectorToArray1DS2(vectorInput1D theValues) {
		if (theValues.size() != 2) throw ArraySizeException();

		arrayS2 outValues{ arrayS2{} };
		for (int i = 0; i < 2; ++i) {
			outValues[i] = theValues[i];
		}
		return outValues;
	}

	arrayS3 GeometryMath::vectorToArray1DS3(vectorInput1D theValues) {
		if (theValues.size() != 3) throw ArraySizeException();

		arrayS3 outValues{ arrayS3{} };
		for (int i = 0; i < 3; ++i) {
			outValues[i] = theValues[i];
		}
		return outValues;
	}

	arrayS4 GeometryMath::vectorToArray1DS4(vectorInput1D theValues) {
		if (theValues.size() != 4) throw ArraySizeException();

		arrayS4 outValues{ arrayS4{} };
		for (int i = 0; i < 4; ++i) {
			outValues[i] = theValues[i];
		}
		return outValues;
	}

	arrayS32 GeometryMath::vectorToArray2DS32(vectorInput2D theValues) {
		if (theValues.size() != 3) throw ArraySizeException();
		if (theValues[0].size() != 2) throw ArraySizeException();
		if (theValues[1].size() != 2) throw ArraySizeException();
		if (theValues[2].size() != 2) throw ArraySizeException();

		arrayS32 outValues{ arrayS32{} };
		for (int i0 = 0; i0 < 3; ++i0) {
			for (int i1 = 0; i1 < 2; ++i1) {
				outValues[i0][i1] = theValues[i0][i1];
			}
		}
		return outValues;
	}

	arrayS33 GeometryMath::vectorToArray2DS33(vectorInput2D theValues) {
		if (theValues.size() != 3) throw ArraySizeException();
		if (theValues[0].size() != 3) throw ArraySizeException();
		if (theValues[1].size() != 3) throw ArraySizeException();
		if (theValues[2].size() != 3) throw ArraySizeException();

		arrayS33 outValues{ arrayS33{} };
		for (int i0 = 0; i0 < 3; ++i0) {
			for (int i1 = 0; i1 < 3; ++i1) {
				outValues[i0][i1] = theValues[i0][i1];
			}
		}
		return outValues;
	}

	arrayS33 GeometryMath::multiplyMatrixToMatrixS3(arrayS33 theMatrix0, arrayS33 theMatrix1) {
		arrayS33 outValues{ arrayS33{} };
		for (int i0 = 0; i0 < theMatrix0.size(); i0++) {
			for (int i1 = 0; i1 < theMatrix0.size(); i1++) {
				outValues[i0][i1] = 0.;
				for (int i2 = 0; i2 < theMatrix0.size(); i2++) {
					outValues[i0][i1] += theMatrix0[i0][i2] * theMatrix1[i2][i1];
				}
			}
		}
		return outValues;
	}

	arrayS3 GeometryMath::multiplyMatrixToVectorS33S3(arrayS33 theMatrix, arrayS3 theVector)
	{
		arrayS3 outValues{ arrayS3{} };
		for (int i0 = 0; i0 < theMatrix.size(); i0++) {
			outValues[i0] = 0.;
			for (int i1 = 0; i1 < theMatrix.size(); i1++) {
				outValues[i0] += theMatrix[i0][i1] * theVector[i1];
			}
		}
		return outValues;
	}

	double GeometryMath::calculateMatrixDeterminantS33(arrayS33 theMatrix)
	{
		double outDeterminant = 0.;
		outDeterminant += theMatrix[0][0] * (theMatrix[1][1] * theMatrix[2][2] - theMatrix[1][2] * theMatrix[2][1]);
		outDeterminant -= theMatrix[0][1] * (theMatrix[1][0] * theMatrix[2][2] - theMatrix[1][2] * theMatrix[2][0]);
		outDeterminant += theMatrix[0][2] * (theMatrix[1][0] * theMatrix[2][1] - theMatrix[1][1] * theMatrix[2][0]);
		return outDeterminant;
	}

	arrayS33 GeometryMath::calculateMatrixInverseS33(arrayS33 theMatrix, double theTolerance)
	{
		// Determine determinant
		double determinant = GeometryMath::calculateMatrixDeterminantS33(theMatrix);

		// Check if inversible matrix
		if (std::fabs(determinant) <= theTolerance) throw ZeroDeterminantException();

		// The inverse matrix
		arrayS33 outInverseMatrix;
		outInverseMatrix[0][0] = (theMatrix[1][1] * theMatrix[2][2] - theMatrix[1][2] * theMatrix[2][1]) / determinant;
		outInverseMatrix[0][1] = (theMatrix[0][2] * theMatrix[2][1] - theMatrix[0][1] * theMatrix[2][2]) / determinant;
		outInverseMatrix[0][2] = (theMatrix[0][1] * theMatrix[1][2] - theMatrix[0][2] * theMatrix[1][1]) / determinant;

		outInverseMatrix[1][0] = (theMatrix[1][2] * theMatrix[2][0] - theMatrix[1][0] * theMatrix[2][2]) / determinant;
		outInverseMatrix[1][1] = (theMatrix[0][0] * theMatrix[2][2] - theMatrix[0][2] * theMatrix[2][0]) / determinant;
		outInverseMatrix[1][2] = (theMatrix[0][2] * theMatrix[1][0] - theMatrix[0][0] * theMatrix[1][2]) / determinant;

		outInverseMatrix[2][0] = (theMatrix[1][0] * theMatrix[2][1] - theMatrix[1][1] * theMatrix[2][0]) / determinant;
		outInverseMatrix[2][1] = (theMatrix[0][1] * theMatrix[2][0] - theMatrix[0][0] * theMatrix[2][1]) / determinant;
		outInverseMatrix[2][2] = (theMatrix[0][0] * theMatrix[1][1] - theMatrix[0][1] * theMatrix[1][0]) / determinant;

		return outInverseMatrix;
	}

	/// <summary>
	/// Ensures the angle is between -2PI and 2PI
	/// </summary>
	double GeometryMath::normalizeAngle(const double& theAngle)
	{
		double outAngle = theAngle;
		while (std::fabs(outAngle) - PI * 2. > TOLERANCE_SENSITIVE) {
			if (outAngle > 0.)
				outAngle -= PI * 2.;
			else
				outAngle += PI * 2.;
		}
		return outAngle;
	}
}

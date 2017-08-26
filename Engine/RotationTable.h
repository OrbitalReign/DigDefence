#pragma once


class RotationTable 
{
public:
	 void ZoomIn(float In_d);
	 static constexpr int RotationAccuracy = 360; // degrees of accuracy for lookup table.

     int RotationArray_x[RotationAccuracy];  // lookup table array
	 int RotationArray_y[RotationAccuracy];
	 int * Array_xPoint = RotationArray_x; // addresses to arrays
	 int * Array_yPoint = RotationArray_y;

	 int DirectionArray_x[RotationAccuracy];  // lookup table array
	 int DirectionArray_y[RotationAccuracy];
	 int * Direct_xPoint = DirectionArray_x; // addresses to arrays
	 int * Direct_yPoint = DirectionArray_y;
private:
	void RotateCalc();
private:
	float CubeWidth = 12.5f;
	float ZoomRate;
	float Hypot;
	float Zoom;
	double Degrees = 0;

};


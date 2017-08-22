#pragma once


class RotationTable 
{
public:
	 void ZoomIn(int In_d);
	 static constexpr int RotationAccuracy = 360; // degrees of accuracy for lookup table.
     int RotationArray_x[RotationAccuracy];  // lookup table array
	 int RotationArray_y[RotationAccuracy];
	 int * Array_xPoint = RotationArray_x; // addresses to arrays
	 int * Array_yPoint = RotationArray_y;
private:
	void RotateCalc();
private:
	float CubeWidth = 12.5f;
	float ZoomRate;
	float Hypot;
	int Zoom;
	double Degrees = 0;

};


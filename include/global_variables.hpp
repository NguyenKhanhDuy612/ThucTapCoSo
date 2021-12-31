#pragma once
#include "list_vertices.hpp"
#include "button.hpp"

ListVertices listv;							// liet ke dinh
int xCursor = xCURSOR;						
int yCursor = yCURSOR;						
int delayRunTime = 1000;						// do tre
bool isSaved = 1;							// Kiem tra do thi luu hay chua
int p[MAX_VERTEX]; 						// luu vet..
float maTran[MAX_VERTEX][MAX_VERTEX];	// ma tran
HWND hwnd;								//win 32

// Nut danh sach de chon menu

Button menuButton[] =	{ 
						  {70, 100, 270, 140, BUTTON_COLOR,	"Thuat Dijkstra"},
						   {15, 245, 115, 285, BUTTON_COLOR,	"Mo File"},
						   {120, 245, 220, 285, BUTTON_COLOR,"Luu File"},
						  {225, 245, 325, 285, BUTTON_COLOR,"Thoat"},
						  {357, 22, 417, 92, BUTTON_COLOR,	"Them Dinh"},
						  {357, 92, 417, 162, BUTTON_COLOR,	"Them/Xoa Cung"},
						  {357, 162, 417, 232, BUTTON_COLOR,"Doi Ten Dinh"},
						  {357, 232, 417, 302, BUTTON_COLOR,"Xoa Dinh"},
						  {357, 302, 417, 372, BUTTON_COLOR,"Di Chuyen"},
						  {357, 372, 417, 442, BUTTON_COLOR,"Xoa Do Thi"},
						  {357, 442, 417, 498, BUTTON_COLOR,"Giup Do"}};

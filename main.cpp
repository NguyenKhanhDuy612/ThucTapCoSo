#include <fstream>						
#include <iostream>					
#include "include/stack.hpp"			// danh sach lien ket
#include "include/colors.hpp"			// màu
#include "include/button.hpp"			// các nút
#include "include/vertex.hpp"			// các dinh
#include "include/list_vertices.hpp"	// quan ly dinh
#include "include/helpers.hpp" 			// Các chuc nang co ban & va cac canh
#include "include/constants.hpp" 		// hang so cua bài
#include "include/global_variables.hpp"	// bien toan cuc

// ---------------------------------------------------------------------------
// 							Ve cua so
// ---------------------------------------------------------------------------
void veCuSo();// ve cua so chinh
void veVungLV();// hien thi do thi
void veVungGH();// hien ket qua
void veVungMenu();// hien thi cac muc
void VungVB();//hien 
void VungMaTran();// ma tran 
void CacNut();// cac nut chuc nang
void XMangHinh();// xuat ra mang hinh
void XDoThi(int);// xuat do thi
void initScreen();//mang hinh
void khoiTaoCS();// khoi tao mang hinh chinh
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//                         Chuc nang tren do thi
// ---------------------------------------------------------------------------
void themDinh();// them dinh
void themTS();// them trong so
void doiTenD();// thay doi ten
void xoaD();//xoa dinh
void chuyenD();// di chuyen dinh 
void xoaDT();// xoa tat ca cac do thi
void help();

void veCanh(int, int, int);// ve cac canh
void veCanhTC();// ve tat ca canh
int chonDinh(int, int boMau = -1);// chon dinh dau hoac cuoi
bool chonDinhDoi(int &, const char*, const char*);// chon dinh can doi
bool chonDinhDC(int &, int &);// chon dinh dau,cuoi
char getKey(); // ham thoat ra
bool ktRong();// kiem tra rong thi bao loi
void nganXep(stack &);// sap xep 


// ---------------------------------------------------------------------------
//                         Xu ly thuat toan
// ---------------------------------------------------------------------------
bool KiemTraTS(); // Kiem tra trong so 
void xDenY();
void dijkstra(int, int);// thuat toan
void kqDijkstra(double [], int, int);// luu va in ra ket qua thuat toan

// ---------------------------------------------------------------------------
//                        Thao tac file chua cai dat xong
// ---------------------------------------------------------------------------
void luuTT();
void thoat();
void moTT();

void luuTT()
{

}

void moTT()
{

}


// ---------------------------------------------------------------------------
//                          Nhap tu ban phim
// ---------------------------------------------------------------------------
bool nhapDinh(char *, int, bool (*)(char));// nhap dinh khi tao
bool nhapTrongSo(float &);// nhap trong so khi tao

// ---------------------------------------------------------------------------
//                         Dinh dang kieu mau, chu
// ---------------------------------------------------------------------------
void kieuChu(int);// kieu mau, kich co
void inRa(float);// xuat ra file 
template <typename Type>
void inRaWl(Type);// in ra bien
void inRa(const char*);// chuyen tu file ra mang hinh
template <typename Type>
void inRaWlb(Type); // in ra bien
void xoaChu(const char*);// thay doi mau kieu cua dinh   
// ---------------------------------------------------------------------------
//                          		Menu
// ---------------------------------------------------------------------------
int nutTim(int, int);// cac nut tim
void mucMenu(int);// cac nut thuc hien
void menu();// tao su kien len cac menu
void quayLaiMenu();// quay lai binh thuong
// ---------------------------------------------------------------------------

int main()
{
    khoiTaoCS();
	menu();
	closegraph();
	return 0;
}
// VE VUNG LAM VIEC
void veVungLV()
{
	setfillstyle(SOLID_FILL, wZONE_COLOR);
	bar(wbLEFT, wTOP, wRIGHT, wBOTTOM);
	setcolor(LINE_COLOR);
	setlinestyle(SOLID_LINE, 1, 2);
	rectangle(wLEFT, wTOP, wRIGHT, wBOTTOM);
}
//// VE VUNG GIOI HAN
void veVungGH()
{
	setcolor(LIMIT_COLOR);
	rectangle(wbLEFT + 2, wTOP + 2, wRIGHT - 2, wBOTTOM - 2);
}
// VE MENU
void veVungMenu()
{
	setbkcolor(BACKGROUND_COLOR);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, USER_CHAR_SIZE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(BLACK);
	outtextxy(5, mTOP - 20, "Thuat toan");
	outtextxy(5, fTOP - 20,"Thao tac file");
	outtextxy(5, aTOP - 20, "Ma tran");
	setlinestyle(SOLID_LINE, 1, 2);
	setcolor(LINE_COLOR);
	rectangle(mLEFT, mTOP, mRIGHT, mBOTTOM);// tao khung
	rectangle(fLEFT, fTOP, fRIGHT, fBOTTOM);
}
// PHAM VI TRUY CAP
void VungVB()
{
	setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
	bar(tLEFT, tTOP, tRIGHT, tBOTTOM);
	setcolor(LINE_COLOR);
	setlinestyle(SOLID_LINE, 1, 2);
	rectangle(tLEFT, tTOP, tRIGHT, tBOTTOM);
	xCursor = xCURSOR; // di chuyen co tro x den dau
	yCursor = yCURSOR;
}
//MA TRAN
void VungMaTran()
{
	setfillstyle(SOLID_FILL, BACKGROUND_COLOR);
	bar(aLEFT, aTOP, aRIGHT, aBOTTOM);
	setcolor(LINE_COLOR);
	setlinestyle(SOLID_LINE, 1, 2);
	rectangle(aLEFT, aTOP, aRIGHT, aBOTTOM);
	const int &n = listv.num + 1;
	if (n == 1) return;
	const float width = float(aRIGHT - aLEFT) / n;
	const float hight = float(aBOTTOM - aTOP) / n;
	setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
	setcolor(BLACK);
	setbkcolor(BACKGROUND_COLOR);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	if (n > aVERTEX_MAX_2)// bao loi khi vuot qua dinh cho phep
	{
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
		outtextxy((aRIGHT + aLEFT) / 2, (aBOTTOM + aTOP) / 2, "KHONG THE HIEN THI.");
		return;
	}
	if (n > aVERTEX_MAX_1) settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	else
	{
		setusercharsize(1, 2, 1, 2);
		settextstyle(BOLD_FONT, HORIZ_DIR, USER_CHAR_SIZE);
	}
	setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
	char str[10];
	for (int i = 1; i < n; ++i)
	{
		line(aLEFT, aTOP + i * hight, aRIGHT, aTOP + i * hight);
		line(aLEFT + i * width, aTOP, aLEFT + i * width, aBOTTOM);
		outtextxy(ADJUST_TEXT_X, i * hight + ADJUST_TEXT_Y, listv.v[i - 1]->name);
		outtextxy(ADJUST_TEXT_X + i * width, ADJUST_TEXT_Y, listv.v[i - 1]->name);
		for (int j = 1; j < n; ++j)
			if (maTran[i - 1][j - 1] != canhRong)
			{
				convertToChar(maTran[i - 1][j - 1], str);// tron helpers
				outtextxy(ADJUST_TEXT_X + j * width, i * hight + ADJUST_TEXT_Y, str);
			}
	}
}
//// VE CUA XO 1250X650
void veCuSo()
{
	setcolor(DOT_COLOR);
	setbkcolor(BACKGROUND_COLOR);
	setfillstyle(CLOSE_DOT_FILL, wZONE_COLOR);
	bar(0, 0, WINDOW_WIDTH, WINDOW_HIGHT);
}
// DUYET CAC NUT THAO TAC
void CacNut()
{
	for (int i = 0; i < NUM_OF_MENU; ++i)
	{
		menuButton[i].nutBT();
		iconNut(menuButton, i);
	}
}

// khoi tao kich thuoc
void khoiTaoCS()
{
	initwindow(WINDOW_WIDTH + 5, WINDOW_HIGHT + 10); // tao cua so co w:1255, h: 660
	setwindowtitle("ThuatToanDijkstra_SV: Nguyen Khanh Duy_GVHD: Nguyen Dinh Hung");
	hwnd = GetActiveWindow();
	::SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE)&~WS_MAXIMIZEBOX);
    initScreen();
    setMatrixTo(maTran, canhRong);
}
// tao ra cac cua so
void initScreen()
{
	veCuSo();
	veVungLV();
	VungVB();
	veVungMenu();
	VungMaTran();
	CacNut();
}
// khoi chay thuat toan dijkstra
void xDenY()
{
	if (ktRong()) return;
	int start, stop;
	if (chonDinhDC(start, stop))
	{
		kieuChu(TEXT_COLOR);
		if (!KiemTraTS())// neu trong so khong am thi chay
		{
			inRaWl("Khoi chay thuat toan Dijkstra:");
			dijkstra(start, stop);
		}
		else// neu trong so am thì in ra và tra ve
		{
			inRaWlb("Do thi ton tai chu trinh am.");
		} 
	}
	return quayLaiMenu();
}
// thuat toan dijkstra
void dijkstra(int start, int stop)
{
	const int &tongDinh = listv.num;
	bool s[tongDinh];
	double d1[tongDinh];
	setArrayTo(s, tongDinh, true);// luu dinh da duyet
	setArrayTo(p, tongDinh, start);// luu vet
	setArrayTo(d1, tongDinh, voCung);
	d1[start] = 0;
	float d; int w;
	while (1)
	{
		d = voCung; // khoi tao do dai tu dau toi moi dinh la vo cung
		w = -1;
		// tim cac diem co duong di truc tiep
		for (int x = 0; x < tongDinh; ++x)
			if (s[x] && d1[x] < d)
			{
				d = d1[x];
				w = x;
			}
		if (w == -1 || w == stop) break;
		s[w] = 0;// danh sach cac diem da xet
		// tim dinh ma co do dai la nho nhat
		for (int x = 0; x < tongDinh; ++x)
		{
			float tSMT = maTran[w][x];
			if (s[x] && tSMT != canhRong && d1[x] > d + tSMT)
			{
				d1[x] = d + tSMT; // thay doi do dai
				p[x] = w;// danh dau diem truoc x la w
			}
		}
	}
	kqDijkstra(d1, start, stop);
}
// ket qua thuat toan Dijkstra
void kqDijkstra(double d1[], int start, int stop)
{
	kieuChu(TEXT_COLOR);
	if (d1[stop] == voCung)
		inRa("Khong ton tai duong di.");
	else
	{
		inRa("Tong trong so: ");
		inRaWl(d1[stop]);
		inRa("Duong di ngan nhat: ");
		stack s;//thay doi thu tu cac dinh nguoc lai
		while (stop != start)
		{
			s.push(stop);
			stop = p[stop];
		}
		s.push(start);
		return nganXep(s);
	}
}
// kiem tra rong
bool ktRong()
{
	// neu do thi chua co dinh nao ma thuc hien se bao loi
	if (listv.num == 0)
	{
		MessageBox(hwnd, "Do thi rong", "Loi", MB_APPLMODAL | MB_ICONERROR);
		return 1;
	}
	return 0;
}
// kiem tra trong so co am khong
bool KiemTraTS()
{
	for (int i = 0; i < listv.num; ++i)
		for (int j = 0; j < listv.num; ++j)
			if (maTran[i][j] != canhRong && maTran[i][j] < 0)
				return 1;
	return 0;
}

// ve 1 canh
void veCanh(int begin, int end, int color)
{
	const int &x1 = listv.v[begin]->x;
	const int &y1 = listv.v[begin]->y;
	const int &x2 = listv.v[end]->x;
	const int &y2 = listv.v[end]->y;
	if (maTran[end][begin] == canhRong || begin < end)
		drawArrow(x1, y1, x2, y2, color, maTran[begin][end]);
}
// ve tat ca canh
void veCanhTC()
{
	for (int i = 0; i < listv.num; ++i)
		for (int j = 0; j < listv.num; ++j)
			if (maTran[i][j] != canhRong)
				veCanh(i, j, EDGE_COLOR);
}
// chon dinh dau hoac dinh cuoi
int chonDinh(int mauX, int boMau)
{
	veVungGH();// lam viec tren vung da gioi han
	int x, y;
	int VTMoi(-1), VTCu(-1);
	while (1)
	{
		if (getKey() == KEY_ESC) break;
		VTMoi = listv.find(mousex(), mousey());
		if (VTMoi != VTCu)// kiem tra vi tri moi co khac vi tri cu khong
		{
			if (VTMoi != -1 && VTMoi != boMau) 
				listv.v[VTMoi]->show(mauX);
			if (VTCu != -1 && VTCu != boMau)
				listv.v[VTCu]->show(VERTEX_COLOR);
			VTCu = VTMoi;
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (!isInWorkingZone(x, y)) break;
			if (VTMoi != -1)
			{
				listv.v[VTMoi]->show(mauX);
				return VTMoi;
			}
		}
		delay(DELAY_VALUE);
	}
	return -1;
}
// chon dinh khi can doi
bool chonDinhDoi(int &start, const char *text1, const char *text2)
{
	kieuChu(TEXT_COLOR);
	inRa(text1);
	start = chonDinh(VERTEX_CHOOSING_COLOR);
	if (start == -1) return 0;
	kieuChu(TEXT_COLOR);
	inRa(listv.v[start]->name);
	inRaWlb(text2);
	return 1;
	
}
// chon dinh dau va den
bool chonDinhDC(int &start, int &stop)
{
	kieuChu(TEXT_COLOR);
	inRa("Chon dinh xuat phat: ");
	start = chonDinh(VERTEX_CHOOSING_COLOR);
	if (start == -1) return 0;
	kieuChu(TEXT_COLOR);
	inRaWl(listv.v[start]->name);
	listv.v[start]->show(VERTEX_CHOSE_COLOR);
	kieuChu(TEXT_COLOR);
	inRa("Chon dinh ket thuc: ");
	stop = chonDinh(VERTEX_CHOOSING_COLOR, start);
	if (stop == -1) return 0;
	kieuChu(TEXT_COLOR);
	inRaWl(listv.v[stop]->name);
	listv.v[stop]->show(VERTEX_CHOSE_COLOR);
	if (start == stop)
	{
		listv.v[stop]->show(VERTEX_COLOR);
		return 0;
	}
	return 1;
}

// ham thoat
char getKey()
{
	if (kbhit())
	{
		char c = getch();
		switch (c)
		{
			case KEY_ESC:
				return KEY_ESC;
			case ARROW_KEY:
				c = getch();
				return c;
			default:
				return KEY_NULL;
		}
	}
	return KEY_NULL;
}
// luu vao ngan xep
void nganXep(stack &s)
{
	int v, u = s.pop();
	kieuChu(TEXT_COLOR);
	inRa(listv.v[u]->name);
	listv.v[u]->show(VERTEX_CHOSE_COLOR);
	while (!s.isEmpty())
	{
		v = s.pop();
		kieuChu(TEXT_HIGHTLIGHT_COLOR);
		inRa("->");
		inRa(listv.v[v]->name);
		veCanh(u, v, EDGE_VISTED_COLOR);
		listv.v[v]->show(VERTEX_VISTED_COLOR);
		u = v;
		if (getKey() == KEY_ESC) return;
		delay(delayRunTime);
	}
}

// kich thuoc, mau
void kieuChu(int color)
{
	setusercharsize(9, 10, 9, 10);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	setbkcolor(BACKGROUND_COLOR);
	setcolor(color);
	settextjustify(LEFT_TEXT, TOP_TEXT);
}
// nhap trong so 
bool nhapTrongSo(float &res)
{
	char str[10];
	nhapDinh(str, 10, inputFloat);
	if (!isFloat(str)) return 0;
	res = roundf(toFloat(str) * 100) / 100;
	if (res > MAX_WEIGHT || res < MIN_WEIGHT)
	{
		char msg[70]; char w[10];
		strcpy(msg, "Trong so khong cho phep.\nTrong so >= ");
		convertToChar(MIN_WEIGHT, w);
		strcat(msg, w);
		strcat(msg, " & Trong so <= ");
		convertToChar(MAX_WEIGHT, w);
		strcat(msg, w);
		MessageBox(hwnd, msg, "Loi", MB_APPLMODAL | MB_ICONERROR);
		return 0;
	}
	return 1;
}
// nhap dinh kieu chu
bool nhapDinh(char *str, int max, bool (*checkKey)(char key))
{
	kieuChu(BLUE);
	int i = 0; str[0] = '\0';
	char key[2] = {'\0', '\0'};
	while (i < max)
	{
		if (kbhit())
		{
			key[0] = getch();
			if (key[0] == KEY_ESC || key[0] == KEY_ENTER) break;
			if (key[0] == KEY_BACKSPACE && i > 0) {--i; key[0] = str[i]; xoaChu(key); str[i] = '\0';}
			else if (checkKey(key[0])) {strcat(str, key); ++i; inRa(key);}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
		delay(DELAY_VALUE);
	}
	return (i > 0);
}
// xoa chu da nhap 
void xoaChu(const char* str)
{
	if (xCursor <= xCURSOR) return;
	const int currentColor = getcolor();
	kieuChu(BACKGROUND_COLOR);
	const int tw = textwidth(str);
	xCursor -= tw;
	inRa(str);
	xCursor -= tw;
	kieuChu(currentColor);
}
// xuat ra mang hinh
void inRa(const char *str)
{
	int const tw = textwidth(str);
	if (xCursor + tw >= tRIGHT)
	{
		xCursor = xCURSOR;
		yCursor += TEXTHIGHT;
	}
	if (yCursor > tBOTTOM - TEXTHIGHT)
	{
		VungVB();
		xCursor = xCURSOR;
		yCursor = yCURSOR;
		kieuChu(TEXT_COLOR);
	}
	outtextxy(xCursor, yCursor, str);
	xCursor += tw;
}
template <typename Type>
void inRaWl(Type s)
{
	inRa(s);
	xCursor = xCURSOR;
	yCursor += TEXTHIGHT;
}
// xuat vo file
void inRa(float value)
{
	char str[MAX_INPUT];
	convertToChar(value, str);
	inRa(str);
}
template <typename Type>
void inRaWlb(Type s)
{
	xCursor = xCURSOR;
	yCursor += TEXTHIGHT;
	inRa(s);
}
// Them dinh vao ma tran
void themDinh()
{
	veVungGH();
	if (listv.num == MAX_VERTEX)
	{
		char msg[45], num[3];
		strcpy(msg, "Qua so luong dinh cho phep");
		convertToChar(MAX_VERTEX, num);
		strcat(msg, num);
		MessageBox(hwnd, msg, "Loi", MB_APPLMODAL | MB_ICONERROR);
	}
	int x, y;
	kieuChu(TEXT_COLOR);
	inRa("Click chuot de them dinh.");
	while (listv.num < MAX_VERTEX)
	{
		if (getKey() == KEY_ESC) break;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (listv.find(x, y) != -1)
			{
				MessageBox(hwnd, "Trung dinh da co\nVui long chon lai.", "Loi",
							MB_APPLMODAL | MB_ICONERROR);
				continue;
			}
			if (isInLimitZone(x, y))
			{
				listv.themDinh(x, y);
				VungMaTran();
				isSaved = 0;
			}
			else break;
		}
		delay(DELAY_VALUE);
	}
}
// THEM TRONG SO 
void themTS()
{
	if (ktRong()) return;
	int begin, end, oldEnd = -1;
	float tSMT;
	kieuChu(TEXT_COLOR);
	inRa("Noi hai dinh de them/xoa cung.");
	while (1)
	{
		begin = chonDinh(VERTEX_CHOOSING_COLOR);
		if (begin == -1) break;
		int x = listv.v[begin]->x;
		int y = listv.v[begin]->y;
		if (ismouseclick(WM_LBUTTONUP)) clearmouseclick(WM_LBUTTONUP);
		while (!ismouseclick(WM_LBUTTONUP))
		{
			setactivepage(1 - getactivepage());
			initScreen();
			veVungGH();
			veCanhTC();
			listv.showAll();
			listv.v[begin]->show(VERTEX_CHOSE_COLOR);
			menuButton[ADD_EDGE_MENU].nutChon();
			iconNut(menuButton, ADD_EDGE_MENU);
			end = listv.find(mousex(), mousey());
			drawArrow(x, y, mousex(), mousey(), EDGE_HIGHTLIGHT_COLOR, 0);
			setvisualpage(getactivepage());
			if (oldEnd != -1 && oldEnd != end && oldEnd != begin)
				listv.v[oldEnd]->show(VERTEX_COLOR);
			if (end != begin && end != -1 && end != oldEnd)
				listv.v[end]->show(VERTEX_CHOOSING_COLOR);
			oldEnd = end;
			if (!isInWorkingZone(mousex(), mousey())) break;
			delay(DELAY_VALUE);
		}
		if (end == -1 || end == begin)
		{
			XDoThi(ADD_EDGE_MENU);
			listv.v[begin]->show(VERTEX_COLOR);
			continue;
		}
		listv.v[end]->show(VERTEX_CHOSE_COLOR);
		setvisualpage(getactivepage());
		maTran[begin][end] = DEFAULT_WEIGHT;
		XDoThi(ADD_EDGE_MENU);
		veCanh(begin, end, EDGE_HIGHTLIGHT_COLOR);
		kieuChu(TEXT_COLOR);
		inRa("Nhap trong so (xoa cung nhap '-') cung ");
		inRa(listv.v[begin]->name);
		inRa("->");
		inRa(listv.v[end]->name);
		inRa(": ");
		if (nhapTrongSo(tSMT)) maTran[begin][end] = tSMT;
		else maTran[begin][end] = canhRong;
		isSaved = 0;
		XDoThi(ADD_EDGE_MENU);
		listv.v[begin]->show(VERTEX_COLOR);
		listv.v[end]->show(VERTEX_COLOR);
	}
}
// DOI TEN
void doiTenD()
{
	if (ktRong()) return;
	int chon;
	while (1)
	{
		if (chonDinhDoi(chon, "Chon dinh can doi ten: ", "Nhap ten moi cho dinh "))
		{
			inRa(listv.v[chon]->name);
			inRa(": ");
			listv.v[chon]->show(VERTEX_CHOSE_COLOR);
			char name[MAX_NAME_LENGTH];
			if (nhapDinh(name, MAX_NAME_LENGTH - 1, inputAscii) && !listv.isExist(name))
			{
				listv.updateCurrentName(name);
				listv.v[chon]->clearName();
				strcpy(listv.v[chon]->name, name);
				VungMaTran();
				isSaved = 0;
			}
			else MessageBox(hwnd, "Trung ten hoac nhap sai", "Loi", MB_APPLMODAL | MB_ICONERROR);
			listv.v[chon]->show(VERTEX_COLOR);
			inRaWl("");
		} else break;
	}
}
// XOA
void xoaD()
{
	if (ktRong()) return;
	while (listv.num > 0)
	{
		kieuChu(TEXT_COLOR);
		inRa("Chon dinh can xoa: ");
		int chon = chonDinh(VERTEX_DELETE_COLOR);
		if (chon == -1) break;
		kieuChu(VERTEX_DELETE_COLOR);
		inRa(listv.v[chon]->name);
//		XoaDinh(chon);
		listv.xoaD(chon); // dinh chon xoa
		XDoThi(DELETEVE_MENU);
		isSaved = 0;
		if (listv.num == 0)
			listv.clear();
	}
}
// DI CHUYEN
void chuyenD()
{
	if (ktRong()) return;
	int x, y;
	kieuChu(TEXT_COLOR);
	inRaWl("Dung thao tac keo/tha dinh de di chuyen tung dinh");
	inRa("hoac Ctr + keo/tha de di chuyen toan bo do thi.");
	while (1)
	{
		int chon = chonDinh(VERTEX_CHOOSING_COLOR);
		if  (chon == -1) break;
		if (ismouseclick(WM_LBUTTONUP)) clearmouseclick(WM_LBUTTONUP);
		isSaved = 0;
		listv.v[chon]->show(VERTEX_CHOSE_COLOR);
		while (!ismouseclick(WM_LBUTTONUP))
		{
			if (ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE, x, y);
				if (!isInLimitZone(x, y)) continue;
				if (GetKeyState(VK_CONTROL) < 0) // Crt + di chuyen tat ca
				{
					int dx = x - listv.v[chon]->x;
					int dy = y - listv.v[chon]->y;
					for (int i = 0; i < listv.num; ++i)
					{
						listv.v[i]->x += dx;
						listv.v[i]->y += dy;
						if (!isInLimitZone(listv.v[i]->x, listv.v[i]->y))
						{
							for (int j = i; j >= 0; --j)
							{
								listv.v[j]->x -= dx;
								listv.v[j]->y -= dy;
							}
							break;
						}
					}
				} else listv.v[chon]->setCoordinate(x, y); // di chuyen 1 dinh
				setactivepage(1 - getactivepage());
				initScreen();
				veVungGH();
				veCanhTC();
				listv.showAll();
				menuButton[MOVEVE_MENU].nutChon();
				iconNut(menuButton, MOVEVE_MENU);
				setvisualpage(getactivepage());
			}
			delay(DELAY_VALUE);
		}
		listv.v[chon]->show(VERTEX_COLOR);
		setvisualpage(getactivepage());
	}
}
// Xoa tat ca do thi
void xoaDT()
{
	if (ktRong()) return;
	if (MessageBox(hwnd, "Ban co chac khong?", "Xoa do thi",
		MB_APPLMODAL| MB_ICONQUESTION | MB_YESNO) == IDYES)
	{
		listv.clear();
		setMatrixTo(maTran, canhRong);
		XDoThi(CLEAN_GRAPH_MENU);
		isSaved = 1;
	}
}
// hien thi giup do
void help()
{
	MessageBox(hwnd,
					"Su dung:\n"
					"Phim <ESC> : Huy chuc nang.\n"
					"CLick chuot phai\n"
					"Chua mo file, luu file duoc\n"
					"1.ThemDinh\n2.ThemDuongDi\n3.DOiTenDinh\n4.XoaDinh\n5.DiChuyen\n6.XoaDoThi\n",
				 	"Help", MB_APPLMODAL | MB_ICONINFORMATION);
}
// ca nut thuc hien
int nutTim(int x, int y)
{
	for (int i = 0; i < NUM_OF_MENU; ++i)
		if (menuButton[i].isButtonClick(x, y))
			return i;
	return -1;
}
// dung thao tac
void quayLaiMenu()
{
	kieuChu(TEXT_COLOR);
	inRaWlb("Nhan phim bat ky hoac click chuot de tiep tuc.");
	if (ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
	while (1)
	{
		if (kbhit()) break;
		if (ismouseclick(WM_LBUTTONDOWN)) break;
		delay(DELAY_VALUE);
	}
	if (ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
}

// xuat ra mang hinh
void XMangHinh()
{
	setactivepage(1 - getactivepage());
	initScreen();
	veCanhTC();
	listv.showAll(VERTEX_COLOR);
	setvisualpage(getactivepage());
}
// xuat do thi
void XDoThi(int mVT)
{
	setactivepage(1 - getactivepage());
	veVungLV();
	VungMaTran();
	VungVB();
	CacNut();
	veCanhTC();
	listv.showAll();
	menuButton[mVT].nutChon();
	iconNut(menuButton, mVT);
	setvisualpage(getactivepage());
}
inline void nutChon(int VT)
{
	if (VT >= ADD_VERTEX_MENU) XMangHinh();
	menuButton[VT].nutChon();
	iconNut(menuButton, VT);
}
inline void nutDanhDau(int VT)
{
	menuButton[VT].nutDanhDau();
	if (VT >= ADD_VERTEX_MENU) menuButton[VT].showButtonHint();
	iconNut(menuButton, VT);
}

inline void nutBT(int VT)
{
	if (VT >= ADD_VERTEX_MENU) XMangHinh();
	menuButton[VT].nutBT();
	iconNut(menuButton, VT);
}
// cap nhat
inline void capNhat(int &VTCu, int &VTMoi, int x, int y)
{
	VTMoi = nutTim(x, y);
	if (VTMoi != VTCu)
	{
		if (VTCu != -1) nutBT(VTCu);
		if (VTMoi != -1) nutDanhDau(VTMoi);
		VTCu = VTMoi;
	}
}
//  menu khi tao su kien
void menu()
{
	int x, y;
	int VTMoi(-1), VTCu(-1);
	while (1)
	{
		if (ismouseclick(WM_MOUSEMOVE))// di chuyen va cap nhat lai vi tri
		{
			getmouseclick(WM_MOUSEMOVE, x, y);
			capNhat(VTCu, VTMoi, x, y);
		}
		if (ismouseclick(WM_LBUTTONDOWN))// neu chon vi tri moi
		{
			clearmouseclick(WM_LBUTTONDOWN);
			if (VTMoi != -1)
			{
				nutChon(VTMoi);
				mucMenu(VTMoi);
			}
			VTCu = -1;
			XMangHinh();
			capNhat(VTCu, VTMoi, mousex(), mousey());
		}
		delay(DELAY_VALUE);// do tre
	}
}
void thoat()
{
	closegraph();
	exit(EXIT_SUCCESS);
}
// cac muc da tao
void mucMenu(int chose)
{
	switch (chose)
	{
		case PATHXY_MENU: 			return xDenY();
		case OPEN_MENU: 			return moTT();
		case SAVE_MENU:				return luuTT();
		case QUIT_MENU: 			return thoat();
		case ADD_VERTEX_MENU:	 	return themDinh();
		case ADD_EDGE_MENU: 		return themTS();
		case RENAME_VERTEX_MENU: 	return doiTenD();
		case DELETEVE_MENU: 		return xoaD();
		case MOVEVE_MENU: 			return chuyenD();
		case CLEAN_GRAPH_MENU: 		return xoaDT();
		case HELP_MENU: 			return help();
		default: return;
	}
}

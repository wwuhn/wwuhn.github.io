// bmp文件格式剖析
typedef unsigned char BYTE;
typedef unsigned short int UINT;
typedef short int WORD;
typedef int DWORD;
typedef long LONG;
 
typedef struct tagBITMAPFILEHEADER
{
    UINT bfType;        /*说明文件的类型*/
    DWORD bfSize;       /*说明文件的大小*/
    UINT bfReserved1;   /*保留，设置为0 */
    UINT bfReserved2;   /*保留，设置为0*/
    DWORD bfOffBits;    /*到图像数据的偏移量*/
} BITMAPFILEHEADER;
 
typedef struct tagBITMAPINFOHEADER
{
    DWORD biSize;       /*BITMAPINFOHEADER结构所需要的字节数*/
    LONG biWidth;       /*图像的宽度，以像素为单位*/
    LONG biHeight;      /*图像的高度，以像素为单位*/
    WORD biPlanes;      /*为目标设备说明位面数，其值设置为1*/
    WORD biBitCount;        /*位数/像素*/
    DWORD biCompression;    /*图像数据压缩的类型：不压缩，或4/8位RLE */
    DWORD biSizeImage;      /*图像的大小，以字节为单位。*/
    LONG biXPelsPerMeter;   /*水平分辨率，用像素/米表示*/
    LONG biYPelsPerMeter;   /*垂直分辨率，用像素/米表示*/
    DWORD biClrUsed;        /*位图使用的彩色表中的颜色索引数：2/16/256/224*/
    DWORD biClrImportant;   /*对图像显示有重要影响的颜色索引的数目，如果是0，表示都重要*/
} BITMAPINFOHEADER;
 
 
typedef struct tagRGBQUAD   /* rgbq */
{
    BYTE rgbBlue;   /*指定蓝色强度*/
    BYTE rgbGreen;  /*指定绿色强度*/
    BYTE rgbRed;    /*指定红色强度*/
    BYTE rgbReserved; /*保留，设置为0 */
} RGBQUAD;
 
typedef struct tagBITMAPINFO
{
    BITMAPINFOHEADER bmiHeader;     // 位图信息头
    RGBQUAD bmiColors[16];          // 颜色表
} BITMAPINFO;
 
//像素信息
typedef unsigned char IMAGEDATA;


//main.cpp

#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
 
//变量定义
BITMAPFILEHEADER bmpHeader;         //文件头
BITMAPINFOHEADER bmpInfoHeader;     //文件信息头
RGBQUAD *colorTable;                //彩色表
IMAGEDATA *bmpData;
 
int main() 
{
    char bmpFileName[80]="bmp16bit.bmp";//bmp文件名
    ifstream bmpFile(bmpFileName, ios::in|ios::binary);
    if(!bmpFile)
    {
        cerr<<"open error!"<<endl;
        exit(1);//退出程序
    }
    /* 读出位图头 */
    //由于“内存对齐问题(这部分为14字节)，无法一次性读入所有信息，此处逐个取出成员
    bmpFile.read((char*)&bmpHeader.bfType, sizeof(bmpHeader.bfType));
    bmpFile.read((char*)&bmpHeader.bfSize, sizeof(bmpHeader.bfSize));
    bmpFile.read((char*)&bmpHeader.bfReserved1, sizeof(bmpHeader.bfReserved1));
    bmpFile.read((char*)&bmpHeader.bfReserved1, sizeof(bmpHeader.bfReserved2));
    bmpFile.read((char*)&bmpHeader.bfOffBits, sizeof(bmpHeader.bfOffBits));
    /* 显示位图头 */
    if(0x4d42!=bmpHeader.bfType)  //前两个字符BM，其ASCII码合成0x4d42，应该是固定的
    {
        cerr<<"not a bmp file!"<<endl;
        exit(1);
    }
    cout<<"位图文件头:"<<endl;
    cout<<"文件类型: BM"<<endl;
    cout<<"文件大小:"<<hex<<bmpHeader.bfSize<<endl;  //hex:用16进制输出
    cout<<"保留字_1:"<<bmpHeader.bfReserved1<<endl;
    cout<<"保留字_2:"<<bmpHeader.bfReserved2<<endl;
    cout<<"实际位图数据的偏移字节数:"<<hex<<bmpHeader.bfOffBits<<endl<<endl;
 
    /* 读出位图信息 */
    bmpFile.read((char*)&bmpInfoHeader, sizeof(bmpInfoHeader));
    /* 显示位图信息 */
    cout<<"位图信息头:"<<endl;
    cout<<"结构体的长度:"<<bmpInfoHeader.biSize<<endl;
    cout<<"位图宽:"<<bmpInfoHeader.biWidth<<endl;
    cout<<"位图高:"<<bmpInfoHeader.biHeight<<endl;
    cout<<"biPlanes平面数:"<<bmpInfoHeader.biPlanes<<endl;
    cout<<"biBitCount采用颜色位数:"<<bmpInfoHeader.biBitCount<<endl;
    cout<<"压缩方式:"<<bmpInfoHeader.biCompression<<endl;
    cout<<"biSizeImage实际位图数据占用的字节数:"<<bmpInfoHeader.biSizeImage<<endl;
    cout<<"X方向分辨率:"<<bmpInfoHeader.biXPelsPerMeter<<endl;
    cout<<"Y方向分辨率:"<<bmpInfoHeader.biYPelsPerMeter<<endl;
    cout<<"使用的颜色数:"<<bmpInfoHeader.biClrUsed<<endl;
    cout<<"重要颜色数:"<<bmpInfoHeader.biClrImportant<<endl<<endl;
 
    /*biClrUsed指定本图象实际用到的颜色数，如果该值为零，则用到的颜色数为2^biBitCount*/
    int colorNum = bmpInfoHeader.biClrUsed;
    if(0==colorNum)
    {
        colorNum = pow(2, bmpInfoHeader.biBitCount);
    }
    colorTable = new RGBQUAD[colorNum];
 
    /* 读取彩色表并显示  */
    cout<<"所用颜色(R:G:B)"<<endl;
    int i;
    for(i=0; i<colorNum; i++)
    {
        bmpFile.read((char*)&colorTable[i].rgbBlue, 1);
        bmpFile.read((char*)&colorTable[i].rgbGreen, 1);
        bmpFile.read((char*)&colorTable[i].rgbRed, 1);
        bmpFile.read((char*)&colorTable[i].rgbReserved, 1);
        cout<<dec<<"["<<i<<"]="<<hex<<int(colorTable[i].rgbRed);
        cout<<":"<<int(colorTable[i].rgbGreen);
        cout<<":"<<int(colorTable[i].rgbBlue)<<endl;
    }
    cout<<endl;
 
    /*读取像素信息*/
    bmpData = new unsigned char[bmpInfoHeader.biSizeImage];
    bmpFile.read((char*)bmpData, bmpInfoHeader.biSizeImage);
 
    /*显示像素信息：下面的显示只提取了数据。BMP中的像素信息是从右上到左上存储，在显示图像时还需要要做处理*/
    /*牵涉到每像素几位-bmpInfoHeader.biBitCount-的问题，下面的代码，有点小绕*/
    int w, h;
    cout<<"下面是像素信息："<<endl;
    for(h=0; h<bmpInfoHeader.biHeight; ++h)
    {
        cout<<"["<<setw(2)<<h<<"]: ";
        for(w=0; w < bmpInfoHeader.biSizeImage / bmpInfoHeader.biHeight; ++w)
        {
            cout<<setw(2)<<int(*(bmpData+h*bmpInfoHeader.biHeight*bmpInfoHeader.biBitCount/8+w))<<" ";
        }
        cout<<endl;
    }
    /*本程序只读出了位图信息，要显示出来，需要调用输出设备的功能了，此处略过*/
    delete[] bmpData;
    delete[] colorTable;
    while(1);
    return 0;
}
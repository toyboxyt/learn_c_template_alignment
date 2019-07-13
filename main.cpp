#include <type_traits>

#include <iostream>


#if 1

#include <Gate/Source/Runtime/Core/Public/Containers/TStaticArray.h>


namespace gate{
#define WINDOW_W (320)
#define WINDOW_H (320)

#define MAX_SPRITE_PACKET_NUM (4096)		//グラフィックのオーダー（同時）限界数


	//---------------------------------------------------------------------------
	//型宣言
	//---------------------------------------------------------------------------
		enum
	{
		enOrderTypePoint,
		enOrderTypeLine,
		enOrderTypeTriangle,
		enOrderTypWired,
		enOrderTypeNoneTexPolygon,
		enOrderTypeTexturePolygon,
		enOrderTypeTextureTriangle,
		enOrderTypeFont,
	};

	//constexpr int Matango(){ return 50; }	
	class GateManager{
	public:
		GateManager(){}

	};

#pragma pack(1)
	typedef struct _packet_2dsprite{

		s32  sType;			// 0	//オーダータイプ
		s32  sAtribute;		// 4	//アトリビュート
		s32  x,y,pr;			// 12	//表示位置
		f32 sx,sy,sz;		// 12	//拡大率
		f32 rx,ry,rz;		// 12	//回転
		s32  pg;				// 4	テクスチャページ
		s32  u,v,w,h,cx,cy;	// 16	//テクスチャ座標＆中心位置

		u32 color[4];		// 16
		//void    *pString;

		u32 opt;				//オプション

		f32 x1[4],y1[4],z1[4],u1[4],v1[4];

		u8 buf;
		u8 buf2;
		u8 buf5;

		//_packet_2dsprite *m_pNextOrder;	//同一プリミティブがある場合の処理
		_packet_2dsprite()
		{

		}
	} packet_2dsprite;
#pragma pop()

	//template<int32 Size>
	//struct TAlignedBytes<Size,1>
	//{
	//	uint8 Pad[Size];
	//};
	// Alignment.


	template<s32 Size>
	struct spritewrapper
	{
		packet_2dsprite spr[Size];
	};

	template<s32 Size>
	struct spritpackets
	{
		TStaticArray<packet_2dsprite, Size> spr;
	};


	class Manager {

		void create() {
			
		}

		//template<s32 size> 
		//spritpackets getSizeArray() {
		//	return 
		//}


	};
}



void main(){

	using namespace gate;

	const int size = 1;
	spritpackets<size> spr;
	spritewrapper<size> spr2;

	printf("packet_2dsprite : %d\n", sizeof(packet_2dsprite));
	printf("packet_2dsprite %d : %d\n", size, sizeof(packet_2dsprite) * size);
	printf("spr : %d \n ", sizeof(spr));
	//packet_2dsprite sp = (packet_2dsprite)spr.spr.Elements[0];

	printf("spr2 : %d \n ", sizeof(spr2));
	spr2.spr[0].x = 99;
	printf("spr2 : %d \n ", spr2.spr[0].x);
	//static_cast<packet_2dsprite>(spr.spr.Elements[0].Padding.Pad.);
	spritewrapper<size*4> spr10;
	printf("spr10 : %d \n ", sizeof(spr10));



}
#endif

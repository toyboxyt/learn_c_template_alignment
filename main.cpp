#include <type_traits>

#include <iostream>


#if 1

#include <Gate/Source/Runtime/Core/Public/Containers/TStaticArray.h>


namespace gate{
#define WINDOW_W (320)
#define WINDOW_H (320)

#define MAX_SPRITE_PACKET_NUM (4096)		//�O���t�B�b�N�̃I�[�_�[�i�����j���E��


	//---------------------------------------------------------------------------
	//�^�錾
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

		s32  sType;			// 0	//�I�[�_�[�^�C�v
		s32  sAtribute;		// 4	//�A�g���r���[�g
		s32  x,y,pr;			// 12	//�\���ʒu
		f32 sx,sy,sz;		// 12	//�g�嗦
		f32 rx,ry,rz;		// 12	//��]
		s32  pg;				// 4	�e�N�X�`���y�[�W
		s32  u,v,w,h,cx,cy;	// 16	//�e�N�X�`�����W�����S�ʒu

		u32 color[4];		// 16
		//void    *pString;

		u32 opt;				//�I�v�V����

		f32 x1[4],y1[4],z1[4],u1[4],v1[4];

		u8 buf;
		u8 buf2;
		u8 buf5;

		//_packet_2dsprite *m_pNextOrder;	//����v���~�e�B�u������ꍇ�̏���
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

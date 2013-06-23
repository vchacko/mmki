/*malayalam keys */
/*
#define MAL_BA		0x00;
#define MAL_CHA		0x01;
#define MAL_DA		0x02;
#define MAL_DHA		0x03;
#define MAL_NGA		0x05;
#define MAL_NJA		0x06;
#define MAL_GA		0x07;
#define MAL_HA		0x08;
#define MAL_JA		0x09;
#define MAL_KA		0x0A;
#define MAL_LA		0x0B;
#define MAL_LLA		0x0C;
#define MAL_MA		0x0D;
#define MAL_NA		0x0E;
#define MAL_NNA		0x0F;
#define MAL_PA		0x10;
#define MAL_RA		0x11;
#define MAL_SA		0x12;
#define MAL_SSA		0x13;
#define MAL_SHA		0x14;
#define MAL_THA		0x15;
#define MAL_TA		0x16;
#define MAL_VA		0x17;
#define MAL_YA		0x18;


*/


DWORD Primary_Letters[26] = {
	0x01000d3e,	//	a
	0x01000d2c,	//	b
	0x01000d1a,	//	c
	0x01000d26,	//	d
	0x01000d46,	//	e
	0x01000d2b,	//	f
	0x01000d19,	//	g
	0x01000d39,	//	h
	0x01000d3f,	//	i
	0x01000d1c,	//	j
	0x01000d15,	//	k
	0x01000d32,	//	l
	0x01000d2e,	//	m
	0x01000d28,	//	n
	0x01000d12,	//	o
	0x01000d2a,	//	p
	0x0100ed31,	//	q
	0x01000d31,	//	r
	0x01000d38,	//	s
	0x01000d24,	//	t
	0x01000d41,	//	u
	0x01000d35,	//	v
	0x01000d35,	//	w
	0x01000d4d,	//	x
	0x01000d2f,	//	y
	0x01000d34,	//	z
};

unsigned int *Primary_Right_Shift[36];
unsigned int **Left_Shift[26];
unsigned int Kootaksharam[100][3];

void Initialize_Kootakshram()
{
	Kootaksharam[0][0] = 0x01000d15;//ka
	Kootaksharam[0][1] = 0x01000d15;
	Kootaksharam[0][2] = 0x0100ed15;

	Kootaksharam[1][0] = 0x01000d15;//ka
	Kootaksharam[1][1] = 0x01000d37;
	Kootaksharam[1][2] = 0x0100ed17;

	Kootaksharam[2][0] = 0x01000d15;//ka
	Kootaksharam[2][1] = 0x01000d33;
	Kootaksharam[2][2] = 0x0100ed16;

	Kootaksharam[3][0] = 0x01000d15;//ka
	Kootaksharam[3][1] = 0x01000d24;
	Kootaksharam[3][2] = 0x0100ed03;

	Kootaksharam[4][0] = 0x01000d15;//ka
	Kootaksharam[4][1] = 0x01000d1f;
	Kootaksharam[4][2] = 0x0100ed3a;

	Kootaksharam[5][0] = 0x01000d2c;//ba
	Kootaksharam[5][1] = 0x01000d2c;
	Kootaksharam[5][2] = 0x0100ed2b;

	Kootaksharam[6][0] = 0x01000d2c;//ba
	Kootaksharam[6][1] = 0x01000d26;
	Kootaksharam[6][2] = 0x0100ed3c;

	Kootaksharam[7][0] = 0x01000d2c;//ba
	Kootaksharam[7][1] = 0x01000d27;
	Kootaksharam[7][2] = 0x0100ed3b;

	Kootaksharam[8][0] = 0x01000d2c;//ba
	Kootaksharam[8][1] = 0x01000d33;
	Kootaksharam[8][2] = 0x0100ed2c;

	Kootaksharam[9][0] = 0x01000d1a;//cha
	Kootaksharam[9][1] = 0x01000d1a;
	Kootaksharam[9][2] = 0x0100ed3d;

	Kootaksharam[10][0] = 0x01000d1a;//cha
	Kootaksharam[10][1] = 0x01000d1b;
	Kootaksharam[10][2] = 0x0100ed08;

	Kootaksharam[11][0] = 0x01000d26;//dha
	Kootaksharam[11][1] = 0x01000d26;
	Kootaksharam[11][2] = 0x0100ed23;

	Kootaksharam[12][0] = 0x01000d26;//dha
	Kootaksharam[12][1] = 0x01000d27;
	Kootaksharam[12][2] = 0x0100ed24;

	Kootaksharam[13][0] = 0x01000d21;//da
	Kootaksharam[13][1] = 0x01000d21;
	Kootaksharam[13][2] = 0x0100ed39;

	Kootaksharam[14][0] = 0x01000d2b;//fa
	Kootaksharam[14][1] = 0x01000d33;
	Kootaksharam[14][2] = 0x0100ed06;

	Kootaksharam[15][0] = 0x01000d17;//ga
	Kootaksharam[15][1] = 0x01000d17;
	Kootaksharam[15][2] = 0x0100ed18;

	Kootaksharam[16][0] = 0x01000d17;//ga
	Kootaksharam[16][1] = 0x01000d2e;
	Kootaksharam[16][2] = 0x0100ed0a;

	Kootaksharam[17][0] = 0x01000d17;//ga
	Kootaksharam[17][1] = 0x01000d28;
	Kootaksharam[17][2] = 0x0100ed04;

	Kootaksharam[18][0] = 0x01000d17;//ga
	Kootaksharam[18][1] = 0x01000d33;
	Kootaksharam[18][2] = 0x0100ed19;

	Kootaksharam[19][0] = 0x01000d19;//nga
	Kootaksharam[19][1] = 0x01000d19;
	Kootaksharam[19][2] = 0x0100ed1b;

	Kootaksharam[20][0] = 0x01000d1e;//nja
	Kootaksharam[20][1] = 0x01000d1e;
	Kootaksharam[20][2] = 0x0100ed1d;

	Kootaksharam[21][0] = 0x01000d1e;//nja
	Kootaksharam[21][1] = 0x01000d1a;
	Kootaksharam[21][2] = 0x0100ed1c;

	Kootaksharam[22][0] = 0x01000d39;//ha
	Kootaksharam[22][1] = 0x01000d33;
	Kootaksharam[22][2] = 0x0100ed38;

	Kootaksharam[23][0] = 0x01000d39;//ha
	Kootaksharam[23][1] = 0x01000d2e;
	Kootaksharam[23][2] = 0x0100ed3e;

	Kootaksharam[24][0] = 0x01000d39;//ha
	Kootaksharam[24][1] = 0x01000d28;
	Kootaksharam[24][2] = 0x0100ed3f;

	Kootaksharam[25][0] = 0x01000d1c;//ja
	Kootaksharam[25][1] = 0x01000d1c;
	Kootaksharam[25][2] = 0x0100ed42;

	Kootaksharam[26][0] = 0x01000d32;//la
	Kootaksharam[26][1] = 0x01000d32;
	Kootaksharam[26][2] = 0x0100ed47;

	Kootaksharam[27][0] = 0x01000d33;//lha
	Kootaksharam[27][1] = 0x01000d33;
	Kootaksharam[27][2] = 0x0100ed32;

	Kootaksharam[28][0] = 0x01000d2e;//ma
	Kootaksharam[28][1] = 0x01000d2e;
	Kootaksharam[28][2] = 0x0100ed2e;

	Kootaksharam[29][0] = 0x01000d2e;//ma
	Kootaksharam[29][1] = 0x01000d33;
	Kootaksharam[29][2] = 0x0100ed46;

	Kootaksharam[30][0] = 0x01000d28;//na
	Kootaksharam[30][1] = 0x01000d28;
	Kootaksharam[30][2] = 0x0100ed27;

	Kootaksharam[31][0] = 0x01000d28;//na
	Kootaksharam[31][1] = 0x01000d24;
	Kootaksharam[31][2] = 0x0100ed25;

	Kootaksharam[32][0] = 0x01000d28;//na
	Kootaksharam[32][1] = 0x01000d2a;
	Kootaksharam[32][2] = 0x0100ed2d;

	Kootaksharam[33][0] = 0x01000d28;//na
	Kootaksharam[33][1] = 0x01000d27;
	Kootaksharam[33][2] = 0x0100ed45;

	Kootaksharam[34][0] = 0x01000d28;//na
	Kootaksharam[34][1] = 0x01000d25;
	Kootaksharam[34][2] = 0x0100ed26;

	Kootaksharam[35][0] = 0x01000d28;//na
	Kootaksharam[35][1] = 0x01000d2e;
	Kootaksharam[35][2] = 0x0100ed28;

	Kootaksharam[36][0] = 0x01000d28;//na
	Kootaksharam[36][1] = 0x01000d26;
	Kootaksharam[36][2] = 0x0100ed40;

	Kootaksharam[37][0] = 0x01000d23;//nn
	Kootaksharam[37][1] = 0x01000d23;
	Kootaksharam[37][2] = 0x0100ed20;

	Kootaksharam[38][0] = 0x01000d23;//nn
	Kootaksharam[38][1] = 0x01000d1f;
	Kootaksharam[38][2] = 0x0100ed1f;

	Kootaksharam[39][0] = 0x01000d23;//nn
	Kootaksharam[39][1] = 0x01000d2e;
	Kootaksharam[39][2] = 0x0100ed43;

	Kootaksharam[40][0] = 0x01000d23;//nn
	Kootaksharam[40][1] = 0x01000d21;
	Kootaksharam[40][2] = 0x0100ed01;

	Kootaksharam[41][0] = 0x01000d23;//nn
	Kootaksharam[41][1] = 0x01000d20;
	Kootaksharam[41][2] = 0x0100ed49;

	Kootaksharam[42][0] = 0x01000d2a;//pa
	Kootaksharam[42][1] = 0x01000d2a;
	Kootaksharam[42][2] = 0x0100ed29;

	Kootaksharam[43][0] = 0x01000d2a;//pa
	Kootaksharam[43][1] = 0x01000d33;
	Kootaksharam[43][2] = 0x0100ed2a;

	Kootaksharam[44][0] = 0x01000d38;//sa
	Kootaksharam[44][1] = 0x01000d38;
	Kootaksharam[44][2] = 0x0100ed37;

	Kootaksharam[45][0] = 0x01000d38;//sa
	Kootaksharam[45][1] = 0x0100ed4b;
	Kootaksharam[45][2] = 0x0100ed07;

	Kootaksharam[46][0] = 0x01000d38;//sa
	Kootaksharam[46][1] = 0x01000d33;
	Kootaksharam[46][2] = 0x0100ed36;

	Kootaksharam[47][0] = 0x01000d38;//sa
	Kootaksharam[47][1] = 0x01000d25;
	Kootaksharam[47][2] = 0x0100ed44;

	Kootaksharam[48][0] = 0x01000d36;//ssa
	Kootaksharam[48][1] = 0x01000d36;
	Kootaksharam[48][2] = 0x0100ed48;

	Kootaksharam[49][0] = 0x01000d36;//ssa
	Kootaksharam[49][1] = 0x01000d1a;
	Kootaksharam[49][2] = 0x0100ed00;

	Kootaksharam[50][0] = 0x01000d36;//ssa
	Kootaksharam[50][1] = 0x01000d33;
	Kootaksharam[50][2] = 0x0100ed34;

	Kootaksharam[51][0] = 0x01000d37;//sha
	Kootaksharam[51][1] = 0x01000d1f;
	Kootaksharam[51][2] = 0x0100ed05;

	Kootaksharam[52][0] = 0x01000d24;//tha
	Kootaksharam[52][1] = 0x01000d24;
	Kootaksharam[52][2] = 0x0100ed21;

	Kootaksharam[53][0] = 0x01000d24;//tha
	Kootaksharam[53][1] = 0x01000d25;
	Kootaksharam[53][2] = 0x0100ed22;

	Kootaksharam[54][0] = 0x01000d24;//tha
	Kootaksharam[54][1] = 0x01000d38;
	Kootaksharam[54][2] = 0x0100ed41;

	Kootaksharam[55][0] = 0x01000d24;//tha
	Kootaksharam[55][1] = 0x01000d2e;
	Kootaksharam[55][2] = 0x0100ed02;

	Kootaksharam[56][0] = 0x01000d24;//tha
	Kootaksharam[56][1] = 0x01000d2d;
	Kootaksharam[56][2] = 0x0100ed09;

	Kootaksharam[57][0] = 0x01000d1f;//ta
	Kootaksharam[57][1] = 0x01000d1f;
	Kootaksharam[57][2] = 0x0100ed1e;

	Kootaksharam[58][0] = 0x01000d35;//va
	Kootaksharam[58][1] = 0x01000d35;
	Kootaksharam[58][2] = 0x0100ed33;

	Kootaksharam[59][0] = 0x01000d2f;//ya
	Kootaksharam[59][1] = 0x01000d2f;
	Kootaksharam[59][2] = 0x0100ed30;



	Kootaksharam[70][0] = 0x0000;



}

void Initialize_Rshift()
{

	Primary_Right_Shift[0] = NULL;											//	0

	Primary_Right_Shift[1] = (unsigned int*)calloc(3,sizeof(unsigned int));//	1
		Primary_Right_Shift[1][0] = 2;
		Primary_Right_Shift[1][1] = 49;
		Primary_Right_Shift[1][2] = 0x01000d67;

	Primary_Right_Shift[2] = (unsigned int*)calloc(3,sizeof(unsigned int));//	2
		Primary_Right_Shift[2][0] = 2;
		Primary_Right_Shift[2][1] = 50;
		Primary_Right_Shift[2][2] = 0x01000d68;

	Primary_Right_Shift[3] = (unsigned int*)calloc(3,sizeof(unsigned int));//	3
		Primary_Right_Shift[3][0] = 2;
		Primary_Right_Shift[3][1] = 51;
		Primary_Right_Shift[3][2] = 0x01000d69;

	Primary_Right_Shift[4] = (unsigned int*)calloc(3,sizeof(unsigned int));//	4
		Primary_Right_Shift[4][0] = 2;
		Primary_Right_Shift[4][1] = 52;
		Primary_Right_Shift[4][2] = 0x01000d6a;
	
	Primary_Right_Shift[5] = (unsigned int*)calloc(3,sizeof(unsigned int));//	5
		Primary_Right_Shift[5][0] = 2;
		Primary_Right_Shift[5][1] = 53;
		Primary_Right_Shift[5][2] = 0x01000d6b;

	Primary_Right_Shift[6] = (unsigned int*)calloc(3,sizeof(unsigned int));//	6
		Primary_Right_Shift[6][0] = 2;
		Primary_Right_Shift[6][1] = 54;
		Primary_Right_Shift[6][2] = 0x01000d6c;

	Primary_Right_Shift[7] = (unsigned int*)calloc(3,sizeof(unsigned int));//	7
		Primary_Right_Shift[7][0] = 2;
		Primary_Right_Shift[7][1] = 55;
		Primary_Right_Shift[7][2] = 0x01000d6d;

	Primary_Right_Shift[8] = (unsigned int*)calloc(3,sizeof(unsigned int));//	8
		Primary_Right_Shift[8][0] = 2;
		Primary_Right_Shift[8][1] = 56;
		Primary_Right_Shift[8][2] = 0x01000d6e;

	Primary_Right_Shift[9] = (unsigned int*)calloc(3,sizeof(unsigned int));//	9
		Primary_Right_Shift[9][0] = 2;
		Primary_Right_Shift[9][1] = 57;
		Primary_Right_Shift[9][2] = 0x01000d6f;

	Primary_Right_Shift[10] = (unsigned int*)calloc(5,sizeof(unsigned int));//	a
		Primary_Right_Shift[10][0] = 4;
		Primary_Right_Shift[10][1] = 0x1000d3e;
		Primary_Right_Shift[10][2] = 0x1000d05;
		Primary_Right_Shift[10][3] = 0x1000d06;
		Primary_Right_Shift[10][4] = 0x1000d02;
	
	Primary_Right_Shift[11] = (unsigned int*)calloc(3,sizeof(unsigned int));//	b
		Primary_Right_Shift[11][0] = 2;
		Primary_Right_Shift[11][1] = 0x1000d2c;
		Primary_Right_Shift[11][2] = 0x1000d2d;

	Primary_Right_Shift[12] = (unsigned int*)calloc(4,sizeof(unsigned int));//	c
		Primary_Right_Shift[12][0] = 3;
		Primary_Right_Shift[12][1] = 0x1000d1a;
		Primary_Right_Shift[12][2] = 0x1000d1b;
		Primary_Right_Shift[12][3] = 0x1000d1d;

	Primary_Right_Shift[13] = (unsigned int*)calloc(6,sizeof(unsigned int));//	d
		Primary_Right_Shift[13][0] = 3;
		Primary_Right_Shift[13][1] = 0x1000d26;
		Primary_Right_Shift[13][2] = 0x1000d21;
//		
		Primary_Right_Shift[13][3] = 0x1000d22;
//		

	Primary_Right_Shift[14] = (unsigned int*)calloc(5,sizeof(unsigned int));//	e
		Primary_Right_Shift[14][0] = 4;
		Primary_Right_Shift[14][1] = 0x1000d46;
		Primary_Right_Shift[14][2] = 0x1000d47;
		Primary_Right_Shift[14][3] = 0x1000d0e;
		Primary_Right_Shift[14][4] = 0x1000d0f;
		

		Primary_Right_Shift[15] = NULL;										//	f

	Primary_Right_Shift[16] = (unsigned int*)calloc(4,sizeof(unsigned int));//	g
		Primary_Right_Shift[16][0] = 3;
		Primary_Right_Shift[16][1] = 0x1000d19;
		Primary_Right_Shift[16][2] = 0x1000d1e;
		Primary_Right_Shift[16][3] = 0x1000d17;

	Primary_Right_Shift[17] = (unsigned int*)calloc(3,sizeof(unsigned int));//	h
		Primary_Right_Shift[17][0] = 2;
		Primary_Right_Shift[17][1] = 0x1000d39;
		Primary_Right_Shift[17][2] = 0x1000d03;

	Primary_Right_Shift[18] = (unsigned int*)calloc(5,sizeof(unsigned int));//	i
		Primary_Right_Shift[18][0] = 4;
		Primary_Right_Shift[18][1] = 0x1000d3f;
		Primary_Right_Shift[18][2] = 0x1000d40;
		Primary_Right_Shift[18][3] = 0x1000d07;
		Primary_Right_Shift[18][4] = 0x1000d57;

	Primary_Right_Shift[19] = (unsigned int*)calloc(3,sizeof(unsigned int));//	j
		Primary_Right_Shift[19][0] = 2;
		Primary_Right_Shift[19][1] = 0x1000d1c;
		Primary_Right_Shift[19][2] = 0x1000d1d;

	Primary_Right_Shift[20] = (unsigned int*)calloc(4,sizeof(unsigned int));//	k
		Primary_Right_Shift[20][0] = 3;
		Primary_Right_Shift[20][1] = 0x1000d15;
		Primary_Right_Shift[20][2] = 0x1000d16;
		Primary_Right_Shift[20][3] = 0x1000d18;

	Primary_Right_Shift[21] = (unsigned int*)calloc(5,sizeof(unsigned int));//	l
		Primary_Right_Shift[21][0] = 4;
		Primary_Right_Shift[21][1] = 0x1000d32;
		Primary_Right_Shift[21][2] = 0x1000d33;
		Primary_Right_Shift[21][3] = 0x100ed55;
		Primary_Right_Shift[21][4] = 0x100ed54;

	Primary_Right_Shift[22] = (unsigned int*)calloc(3,sizeof(unsigned int));//	m
		Primary_Right_Shift[22][0] = 2;
		Primary_Right_Shift[22][1] = 0x1000d2e;
		Primary_Right_Shift[22][2] = 0x1000d02;

	Primary_Right_Shift[23] = (unsigned int*)calloc(5,sizeof(unsigned int));//	n
		Primary_Right_Shift[23][0] = 4;
		Primary_Right_Shift[23][1] = 0x1000d28;
		Primary_Right_Shift[23][2] = 0x1000d23;
		Primary_Right_Shift[23][3] = 0x100ed52;
		Primary_Right_Shift[23][4] = 0x100ed51;

	Primary_Right_Shift[24] = (unsigned int*)calloc(3,sizeof(unsigned int));//	o
		Primary_Right_Shift[24][0] = 2;
		Primary_Right_Shift[24][1] = 0x1000d12;
		Primary_Right_Shift[24][2] = 0x1000d57;
		
	Primary_Right_Shift[25] = NULL;											//	p

	Primary_Right_Shift[26] = (unsigned int*)calloc(3,sizeof(unsigned int));//	q
		Primary_Right_Shift[26][0] = 3;
		Primary_Right_Shift[26][1] = 0x100ed31;
		Primary_Right_Shift[26][2] = 0x1000d46;
		Primary_Right_Shift[26][3] = 0x1000d47;

	Primary_Right_Shift[27] = (unsigned int*)calloc(5,sizeof(unsigned int));//	r
		Primary_Right_Shift[27][0] = 4;
		Primary_Right_Shift[27][1] = 0x1000d31;
		Primary_Right_Shift[27][2] = 0x1000d30;	
		Primary_Right_Shift[27][3] = 0x100ed53;	
		Primary_Right_Shift[27][4] = 0x1000d0b;	

	Primary_Right_Shift[28] = (unsigned int*)calloc(4,sizeof(unsigned int));//	s
		Primary_Right_Shift[28][0] = 3;
		Primary_Right_Shift[28][1] = 0x1000d38;
		Primary_Right_Shift[28][2] = 0x1000d36;	
		Primary_Right_Shift[28][3] = 0x1000d37;

	Primary_Right_Shift[29] = (unsigned int*)calloc(6,sizeof(unsigned int));//	t
		Primary_Right_Shift[29][0] = 5;
		Primary_Right_Shift[29][1] = 0x1000d24;
		Primary_Right_Shift[29][2] = 0x1000d1f;
		Primary_Right_Shift[29][3] = 0x1000d20;
		Primary_Right_Shift[29][4] = 0x1000d27;
		Primary_Right_Shift[29][5] = 0x1000d25;

	Primary_Right_Shift[30] = (unsigned int*)calloc(4,sizeof(unsigned int));//	u
		Primary_Right_Shift[30][0] = 3;
		Primary_Right_Shift[30][1] = 0x1000d41;	
		Primary_Right_Shift[30][2] = 0x1000d42;
		Primary_Right_Shift[30][3] = 0x1000d09;
	

		Primary_Right_Shift[31] =(unsigned int*)calloc(3,sizeof(unsigned int));//	v
		Primary_Right_Shift[31][0] = 2;
		Primary_Right_Shift[31][1] = 0x1000d35;
		Primary_Right_Shift[31][2] = 0x100ed35;

		Primary_Right_Shift[32] = NULL;										//	w
	
	Primary_Right_Shift[33] = (unsigned int*)calloc(5,sizeof(unsigned int));//	x
		Primary_Right_Shift[33][0] = 4;
		Primary_Right_Shift[33][1] = 0x1000d4d;
		Primary_Right_Shift[33][2] = 0x100ed35;
		Primary_Right_Shift[33][3] = 0x100ed2f;
		Primary_Right_Shift[33][4] = 0x1000d43;

		Primary_Right_Shift[34] = (unsigned int*)calloc(3,sizeof(unsigned int));//	y
		Primary_Right_Shift[34][0] = 2;
		Primary_Right_Shift[34][1] = 0x1000d2f;
		Primary_Right_Shift[34][2] = 0x100ed2f;
	Primary_Right_Shift[35] = (unsigned int*)calloc(2,sizeof(unsigned int));//	z
		Primary_Right_Shift[35][0] = 1;
		Primary_Right_Shift[35][1] = 0x1000d34;
}
void Initialize_Lshift()
{
//	Initialize array for left shift

	Left_Shift[0] = (unsigned int**)calloc(4,sizeof(unsigned int*));		//	a

	Left_Shift[0][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
	Left_Shift[0][0][0] = 2;
	Left_Shift[0][1] = (unsigned int*)calloc(2,sizeof(unsigned int));
		Left_Shift[0][1][0] = 2;
		Left_Shift[0][1][1] = 0x1000d3e;
		Left_Shift[0][1][2] = 0x1000d06;
	Left_Shift[0][2] = NULL;

	Left_Shift[0][3] = (unsigned int*)calloc(2,sizeof(unsigned int));
		Left_Shift[0][3][0] = 2;
		Left_Shift[0][3][1] = 0x1000d06;
		Left_Shift[0][3][2] = 0x1000d3e;

	Left_Shift[1] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	b

	Left_Shift[1][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
	Left_Shift[1][0][0] = 2;

	Left_Shift[1][1] = (unsigned int*)calloc(5,sizeof(unsigned int));
		Left_Shift[1][1][0] = 4;
		Left_Shift[1][1][1] = 0x1000d2c;
		Left_Shift[1][1][2] = 0x100ed2b;
		Left_Shift[1][1][3] = 0x100ed3c;
		Left_Shift[1][1][4] = 0x100ed3b;

	Left_Shift[1][2] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[1][2][0] = 2;
		Left_Shift[1][2][1] = 0x1000d2d;
		Left_Shift[1][2][2] = 0x100ed09;

	Left_Shift[2] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	c
	Left_Shift[2][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
	Left_Shift[2][0][0] = 1;

	Left_Shift[2][1] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[2][1][0] = 3;
		Left_Shift[2][1][1] = 0x1000d1a;
		Left_Shift[2][1][2] = 0x100ed3d;
		Left_Shift[2][1][3] = 0x100ed08;


	Left_Shift[2][2] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[2][2][0] = 2;
		Left_Shift[2][2][1] = 0x1000d1b;
		Left_Shift[2][2][2] = 0x100ed08;

	Left_Shift[3] = (unsigned int**)calloc(3,sizeof(unsigned int*));		//	d
	Left_Shift[3][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[3][0][0] = 2;
	Left_Shift[3][1] = (unsigned int*)calloc(5,sizeof(unsigned int));
		Left_Shift[3][1][0] = 4;
		Left_Shift[3][1][1] = 0x1000d26;
		Left_Shift[3][1][2] = 0x100ed23;
		Left_Shift[3][1][3] = 0x100ed24;
		Left_Shift[3][1][4] = 0x100ed40;

	Left_Shift[3][2] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[3][2][0] = 2;
		Left_Shift[3][2][1] = 0x1000d21;
		Left_Shift[3][2][2] = 0x100ed39;

	Left_Shift[4] = (unsigned int**)calloc(6,sizeof(unsigned int*));		//	e
	Left_Shift[4][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[4][0][0] = 2;
	Left_Shift[4][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[4][1][0] = 2;
		Left_Shift[4][1][1] = 0x1000d46;
		Left_Shift[4][1][2] = 0x1000d47;

	Left_Shift[4][2] = NULL;
	Left_Shift[4][3] = NULL;

	Left_Shift[4][4] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[4][4][0] = 2;
		Left_Shift[4][4][1] = 0x1000d47;
		Left_Shift[4][4][2] = 0x1000d46;

	Left_Shift[5] = NULL;													//	f

	Left_Shift[6] = (unsigned int**)calloc(4,sizeof(unsigned int*));		//	g
	Left_Shift[6][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[6][0][0] = 3;
	Left_Shift[6][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[6][1][0] = 2;
		Left_Shift[6][1][1] = 0x1000d19;
		Left_Shift[6][1][2] = 0x100ed1b;
	Left_Shift[6][2] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[6][2][0] = 3;
		Left_Shift[6][2][1] = 0x1000d1e;
		Left_Shift[6][2][2] = 0x100ed1d;
		Left_Shift[6][2][3] = 0x100ed1c;
	Left_Shift[6][3] = (unsigned int*)calloc(5,sizeof(unsigned int));
		Left_Shift[6][3][0] = 4;
		Left_Shift[6][3][1] = 0x1000d17;
		Left_Shift[6][3][2] = 0x100ed18;
		Left_Shift[6][3][3] = 0x100ed04;
		Left_Shift[6][3][4] = 0x100ed0a;

	Left_Shift[7] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	h
	Left_Shift[7][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[7][0][0] = 1;
	Left_Shift[7][1] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[7][1][0] = 4;
		Left_Shift[7][1][1] = 0x1000d39;
		Left_Shift[7][1][2] = 0x100ed38;
		Left_Shift[7][1][3] = 0x100ed3e;
		Left_Shift[7][1][4] = 0x100ed3f;

	Left_Shift[8] = (unsigned int**)calloc(4,sizeof(unsigned int*));		//	i
	Left_Shift[8][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[8][0][0] = 3;
	Left_Shift[8][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[8][1][0] = 2;
		Left_Shift[8][1][1] = 0x1000d3f;
		Left_Shift[8][1][2] = 0x1000d40;
	Left_Shift[8][2] = NULL;
	Left_Shift[8][3] = NULL;
	Left_Shift[8][4] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[8][4][0] = 2;
		Left_Shift[8][4][1] = 0x1000d40;
		Left_Shift[8][4][2] = 0x1000d3f;

	Left_Shift[9] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	j
	Left_Shift[9][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[9][0][0] = 1;
	Left_Shift[9][1] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[9][1][0] = 2;
		Left_Shift[9][1][1] = 0x1000d1c;
		Left_Shift[9][1][2] = 0x100ed42;
//		Left_Shift[9][1][3] = ; // Not in unicode map

	Left_Shift[10] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	k
	Left_Shift[10][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[10][0][0] = 1;
	Left_Shift[10][1] = (unsigned int*)calloc(8,sizeof(unsigned int));
		Left_Shift[10][1][0] = 7;
		Left_Shift[10][1][1] = 0x1000d15;
		Left_Shift[10][1][2] = 0x100ed15;
		Left_Shift[10][1][3] = 0x100ed17;
		Left_Shift[10][1][4] = 0x100ed16;
		Left_Shift[10][1][5] = 0x100ed03;
		Left_Shift[10][1][6] = 0x100ed3a;
		Left_Shift[10][1][7] = 0x100ed1a;

	Left_Shift[11] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	l
	Left_Shift[11][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[11][0][0] = 1;
	Left_Shift[11][1] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[11][1][0] = 3;
		Left_Shift[11][1][1] = 0x1000d32;
		Left_Shift[11][1][2] = 0x100ed47;
		Left_Shift[11][1][3] = 0x100ed54;
	Left_Shift[11][2] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[11][2][0] = 3;
		Left_Shift[11][2][1] = 0x1000d33;
		Left_Shift[11][2][2] = 0x100ed32;
		Left_Shift[11][2][3] = 0x100ed55;
		
	Left_Shift[12] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	m
	Left_Shift[12][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[12][0][0] = 1;
	Left_Shift[12][1] = (unsigned int*)calloc(6,sizeof(unsigned int));
		Left_Shift[12][1][0] = 5;
		Left_Shift[12][1][1] = 0x1000d2e;
		Left_Shift[12][1][2] = 0x100ed2e;
		Left_Shift[12][1][3] = 0x100ed46;
		Left_Shift[12][1][4] = 0x100ed02;
		Left_Shift[12][1][5] = 0x100ed28;

	Left_Shift[13] = (unsigned int**)calloc(3,sizeof(unsigned int*));		//	n
	Left_Shift[13][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[13][0][0] = 2;
	Left_Shift[13][1] = (unsigned int*)calloc(11,sizeof(unsigned int));
		Left_Shift[13][1][0] = 10;
		Left_Shift[13][1][1] = 0x1000d28;
		Left_Shift[13][1][2] = 0x100ed52;
		Left_Shift[13][1][3] = 0x100ed27;
		Left_Shift[13][1][4] = 0x100ed2d;
		Left_Shift[13][1][5] = 0x100ed25;
		Left_Shift[13][1][6] = 0x100ed40;
		Left_Shift[13][1][7] = 0x100ed45;
		Left_Shift[13][1][8] = 0x100ed26;
		Left_Shift[13][1][9] = 0x100ed28;
		Left_Shift[13][1][10] = 0x100ed4a;
	Left_Shift[13][2] = (unsigned int*)calloc(6,sizeof(unsigned int));
		Left_Shift[13][2][0] = 6;
		Left_Shift[13][2][1] = 0x1000d23;
		Left_Shift[13][2][2] = 0x100ed1f;
		Left_Shift[13][2][3] = 0x100ed51;
		Left_Shift[13][2][4] = 0x100ed20;
		Left_Shift[13][2][5] = 0x100ed43;
		Left_Shift[13][2][6] = 0x100ed01;

	Left_Shift[14] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	o
	Left_Shift[14][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[14][0][0] = 1;
	Left_Shift[14][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[14][1][0] = 2;
		Left_Shift[14][1][1] = 0x1000d12;
		Left_Shift[14][1][2] = 0x1000d57;

	Left_Shift[15] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	p
	Left_Shift[15][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[15][0][0] = 1;
	Left_Shift[15][1] = (unsigned int*)calloc(5,sizeof(unsigned int));
		Left_Shift[15][1][0] = 4;
		Left_Shift[15][1][1] = 0x1000d2a;
		Left_Shift[15][1][2] = 0x100ed29;
		Left_Shift[15][1][3] = 0x100ed2a;
		Left_Shift[15][1][4] = 0x100ed2d;

	Left_Shift[16] = NULL;													//	q

	Left_Shift[17] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	r
	Left_Shift[17][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[17][0][0] = 1;
	Left_Shift[17][1] = (unsigned int*)calloc(5,sizeof(unsigned int));
		Left_Shift[17][1][0] = 4;
		Left_Shift[17][1][1] = 0x1000d31;
		Left_Shift[17][1][2] = 0x100ed4b;
		Left_Shift[17][1][3] = 0x100ed4a;
		Left_Shift[17][1][4] = 0x100ed53;

	Left_Shift[18] = (unsigned int**)calloc(4,sizeof(unsigned int*));		//	s
	Left_Shift[18][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[18][0][0] = 3;
	Left_Shift[18][1] = (unsigned int*)calloc(6,sizeof(unsigned int));
		Left_Shift[18][1][0] = 5;
		Left_Shift[18][1][1] = 0x1000d38;
		Left_Shift[18][1][2] = 0x100ed37;
		Left_Shift[18][1][3] = 0x100ed07;
		Left_Shift[18][1][4] = 0x100ed36;
		Left_Shift[18][1][5] = 0x100ed44;
	Left_Shift[18][2] = (unsigned int*)calloc(5,sizeof(unsigned int));
		Left_Shift[18][2][0] = 4;
		Left_Shift[18][2][1] = 0x1000d36;
		Left_Shift[18][2][2] = 0x100ed48;
		Left_Shift[18][2][3] = 0x100ed00;
		Left_Shift[18][2][4] = 0x100ed34;
	Left_Shift[18][3] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[18][3][0] = 2;
		Left_Shift[18][3][1] = 0x1000d37;
		Left_Shift[18][3][2] = 0x100ed05;

	Left_Shift[19] = (unsigned int**)calloc(6,sizeof(unsigned int*));		//	t
	Left_Shift[19][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[19][0][0] = 5;
	Left_Shift[19][1] = (unsigned int*)calloc(7,sizeof(unsigned int));
		Left_Shift[19][1][0] = 6;
		Left_Shift[19][1][1] = 0x1000d24;
		Left_Shift[19][1][2] = 0x100ed21;
		Left_Shift[19][1][3] = 0x100ed22;
		Left_Shift[19][1][4] = 0x100ed41;
		Left_Shift[19][1][5] = 0x100ed02;
		Left_Shift[19][1][6] = 0x100ed09;

	Left_Shift[19][2] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[19][2][0] = 2;
		Left_Shift[19][2][1] = 0x1000d1f;
		Left_Shift[19][2][2] = 0x100ed1e;

	Left_Shift[19][3] = NULL;

	Left_Shift[19][4] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[19][4][0] = 2;
		Left_Shift[19][4][1] = 0x1000d27;
		Left_Shift[19][4][2] = 0x100ed45;
	
	Left_Shift[19][5] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[19][5][0] = 2;
		Left_Shift[19][5][1] = 0x1000d25;
		Left_Shift[19][5][2] = 0x100ed26;

	Left_Shift[20] = (unsigned int**)calloc(5,sizeof(unsigned int*));		//	u
	Left_Shift[20][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[20][0][0] = 4;
	Left_Shift[20][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[20][1][0] = 2;
		Left_Shift[20][1][1] = 0x1000d41;
		Left_Shift[20][1][2] = 0x1000d42;

	Left_Shift[20][2] = NULL;
	Left_Shift[20][3] = NULL;
	Left_Shift[20][4] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[20][4][0] = 2;
		Left_Shift[20][4][1] = 0x1000d42;
		Left_Shift[20][4][2] = 0x1000d41;

	Left_Shift[21] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	v
	Left_Shift[21][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[21][0][0] = 1;
	Left_Shift[21][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[21][1][0] = 2;
		Left_Shift[21][1][1] = 0x1000d35;
		Left_Shift[21][1][2] = 0x100ed33;

	Left_Shift[22] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	w
	Left_Shift[22][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[22][0][0] = 1;
	Left_Shift[22][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[22][1][0] = 2;
		Left_Shift[22][1][1] = 0x1000d35;
		Left_Shift[22][1][2] = 0x100ed33;												

	Left_Shift[23] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	x
	Left_Shift[23][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[23][0][0] = 3;
	Left_Shift[23][1] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[23][1][0] = 3;
		Left_Shift[23][1][1] = 0x1000d4d;
		Left_Shift[23][1][2] = 0x1000d43;
		Left_Shift[23][1][3] = 0x100ed2f;
	Left_Shift[23][2] = NULL;
	Left_Shift[23][3] = (unsigned int*)calloc(4,sizeof(unsigned int));
		Left_Shift[23][3][0] = 3;
		Left_Shift[23][3][1] = 0x100ed2f;
		Left_Shift[23][3][2] = 0x1000d43;
		Left_Shift[23][3][3] = 0x1000d4d;

	Left_Shift[24] = (unsigned int**)calloc(2,sizeof(unsigned int*));		//	y
	Left_Shift[24][0] = (unsigned int*)calloc(1,sizeof(unsigned int));
		Left_Shift[24][0][0] = 1;
	Left_Shift[24][1] = (unsigned int*)calloc(3,sizeof(unsigned int));
		Left_Shift[24][1][0] = 2;
		Left_Shift[24][1][1] = 0x1000d2f;
		Left_Shift[24][1][2] = 0x100ed30;

	Left_Shift[25] = NULL;													//	z

}
void Initialize()
{
	Initialize_Rshift();
	Initialize_Lshift();
	Initialize_Kootakshram();

}

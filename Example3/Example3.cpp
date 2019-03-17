#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

#include <math.h>

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif // M_PI

void locateBlockIfAir(BlockID block, int x, int y, int z, bool emptyOnly)
{
	if (!emptyOnly || getBlockType(x, y, z) == BLOCK_AIR) {		// emptyOnly가 거짓이거나
																// 현재 블록이 AIR인 경우에만 블록을 놓는다.
		locateBlock(block, x, y, z);
	}
}

// Modified Bresenham Algorithm
// https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
// 2차원 라인을 그린다(y2는 무시)
void drawLine(BlockID block, int x1, int y1, int z1, int x2, int y2, int z2, bool emptyOnly)
{
	int dx = abs(x2 - x1), sx = (x1 < x2) ? 1 : -1;
	int dz = abs(z2 - z1), sz = (z1 < z2) ? 1 : -1;

	locateBlockIfAir(block, x1, y1, z1, emptyOnly);
	for (int err = (dx > dz ? dx : -dz) / 2; x1 != x2 || z1 != z2; ) {
		int e2 = err;

		if (e2 > -dx) { err -= dz; x1 += sx; }
		if (e2 < dz) { err += dx; z1 += sz; }

		locateBlockIfAir(block, x1, y1, z1, emptyOnly);
	}
}

void drawForward(BlockID block, int count, bool emptyOnly) 
{
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);				// 현재 플레이어의 위치를 획득한다.

	double dir = getPlayerDirection();				// 현재 플레이어의 방향을 획득한다.
													// z축을 기준으로 시계방향의 각도
	double radian = dir * M_PI / 180.;				// 삼각 함수를 사용하기 위해서 RADIAN 값으로 변환한다.

	int dx = -count * sin(radian);					// 라인의 끝이 되는 x좌표
	int dz = count * cos(radian);					// 라인의 끝이 되는 z좌표

	drawLine(block, px, py, pz, px + dx, py, pz + dz, emptyOnly);		// 두 점을 잇는 라인을 그린다.
}

int main()
{
	BlockID diamond = createBlock(BLOCK_DIAMOND);	// DIAMOND 블록을 생성한다.
	drawForward(diamond, 10, true);					// DIAMOND 블록을 플레이어의 앞으로 10개 놓는다(비어 있는 경우에만)
}
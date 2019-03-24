#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

#include <math.h>

#define M_PI       3.14159265358979323846   // pi

// 플레이어 앞으로 distance만큼 떨어진 곳에
// deltaX, deltaY, deltaZ 만큼의 건물이 만들어질 좌표를 반환한다.
// (sx, sy, sz) - (ex, sy, ez)
// sx < ex, sy < ey, sz < ez가 보장된다.
void getPlayerFrontSpace(int distance, int deltaX, int deltaY, int deltaZ, int* sx, int* sy, int* sz, int* ex, int* ey, int* ez)
{
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);

	double dir = getPlayerDirection();		// 현재 플레이어의 방향을 획득한다.
											// z축을 기준으로 시계방향의 각도
	double radian = dir * M_PI / 180.;		// 삼각 함수를 사용하기 위해서 RADIAN 값으로 변환한다.
	int dx = -distance * sin(radian);		// 라인의 끝이 되는 x좌표
	int dz = distance * cos(radian);		// 라인의 끝이 되는 z좌표

	if (dx > 0) {
		*sx = px + dx - deltaX / 2;
		*ex = *sx + deltaX - 1;
	}
	else {
		*ex = px + dx + deltaX / 2;
		*sx = *ex - deltaX + 1;
	}

	if (dz > 0) {
		*sz = pz + dz - deltaZ / 2;
		*ez = *sz + deltaZ - 1;
	}
	else {
		*ez = pz + dz + deltaZ / 2;
		*sz = *ez - deltaZ + 1;
	}

	*sy = py;
	*ey = *sy + deltaY - 1;
}

int main()
{
	int sx, sy, sz;
	int ex, ey, ez;

	const int delta = 9;
	getPlayerFrontSpace(10, delta, delta, delta/2 + 1, &sx, &sy, &sz, &ex, &ey, &ez);

	printf("(%d, %d, %d) - (%d, %d, %d)\n", sx, sy, sz, ex, ey, ez);

	BlockID diamond = createBlock(BLOCK_DIAMOND);
	int x, y, z;
	for (y = 0; y < 3; y++) {
		for (x = y; x < delta - y; x++) {
			for (z = y; z < delta - y; z++) {
				locateBlock(diamond, sx + x, sy + y, sz + z);
			}
		}
	}

	BeaconID beacon = createBeacon();
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(beacon, sx + x, sy + y - 1, sz + z);
		}
	}

	GlassID glass1 = createGlass(COLOR_YELLOW);
	GlassID glass2 = createGlass(COLOR_GREEN);
	int n;
	for (x = y, n = 0; x < delta - y; x++) {
		for (z = y; z < delta - y; z++, n++) {
			locateBlock((n%2)?glass1:glass2, sx + x, sy + y, sz + z);
		}
	}

}

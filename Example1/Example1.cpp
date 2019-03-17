#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);				// 현재 플레이어의 위치를 획득한다.

	BlockID stone = createBlock(BLOCK_STONE);		// STONE 블록을 생성한다.
	BlockID dirt = createBlock(BLOCK_DIRT);			// DIRT 블록을 생성한다.

	int x, z, n = 0;								// n: 블록을 놓을 때마다 하나씩 증가한다.
	for (x = -5; x < 6; x++) {						// x: 플레이어의 위치에서 x축으로 -5부터 5까지
		for (z = -5; z < 6; z++, n++) {				// z: 플레이어의 위치에서 z축으로 -5부터 5까지
			if ( n % 2 == 0 ) locateBlock(stone, px + x, py - 1, pz + z);	// n이 짝수이면 STONE 블록을 놓는다.
			else locateBlock(dirt, px + x, py - 1, pz + z);					// 그렇지 않으면 DIRT 블록을 놓는다.
		}
	}
}
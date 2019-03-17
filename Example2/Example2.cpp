#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")


void testBlock(int x, int y, int z) {
	int count = 50;
	for (int i = 0; i < count; i++) {
		BlockID block = createBlock(BlockType(i + 1));
		locateBlock(block, x, y, z + 2 * i + 1);
	}
}

void testOre(int x, int y, int z) {
	int count = 9;
	for (int i = 0; i < count; i++) {
		BlockID block = createOre(OreType(i + 1));
		locateOre(block, x, y, z + 2 * i + 1);
	}
}

void testBricks(int x, int y, int z) {
	int count = 7;
	for (int i = 0; i < count; i++) {
		BlockID block = createBricks(BricksType(i + 1));
		locateBricks(block, x, y, z + 2 * i + 1);
	}
}

void testPlanks(int x, int y, int z) {
	int count = 6;
	for (int i = 0; i < count; i++) {
		BlockID block = createPlanks(PlanksType(i + 1));
		locatePlanks(block, x, y, z + 2 * i + 1);
	}
}

void testWood(int x, int y, int z) {
	int count = 24;
	for (int i = 0; i < count; i++) {
		BlockID block = createWood(WoodType(i / 4 + 1), WoodStrip(i % 4));
		locateWood(block, x, y, z + 2 * i + 1);
	}
}

void testStairs(int x, int y, int z) {
	BlockOrientation orientations[4] = { FACING_EAST, FACING_WEST, FACING_SOUTH, FACING_NORTH };
	int count = 14;

	for (int i = 0; i < count; i++) {
		BlockID block = createStairs(StairsType(i + 1), i % 2 == 0);
		installStairs(block, x, y, z + 2 * i + 1, orientations[i % 4]);
	}
}

void testDoor(int x, int y, int z) {
	BlockOrientation orientations[4] = { FACING_EAST, FACING_WEST, FACING_SOUTH, FACING_NORTH };
	int count = 13;
	for (int i = 0; i < count; i++) {
		BlockID block = createDoor(DoorType(i + 1), i % 2 == 0, DoorHinge(i % 2));
		installDoor(block, x, y, z + 2 * i + 1, orientations[i % 4]);
	}
}

void testFence(int x, int y, int z) {
	int count = 7;
	for (int i = 0; i < count; i++) {
		BlockID block = createFence(FenceType(i + 1));
		locateFence(block, x, y, z + i + 1);
		locateFence(block, x + 1, y, z + i + 1);
	}
}

void testPane(int x, int y, int z) {
	int count = 2;
	for (int i = 0; i < count; i++) {
		BlockID block = createPane(PaneType(i + 1));
		locatePane(block, x, y, z + i + 1);
		locatePane(block, x + 1, y, z + i + 1);
	}

	count = 16;
	for (int i = 0; i < count; i++) {
		BlockID block = createPane(BlockColor(i));
		locatePane(block, x, y, z + i + 3);
		locatePane(block, x + 1, y, z + i + 3);
	}
}

void testFlower(int x, int y, int z) {
	int count = 17;
	for (int i = 0; i < count; i++) {
		BlockID block = createFlower(FlowerType(i + 1));
		locateFlower(block, x, y, z + 2 * i + 1);
	}
}

void testSlab(int x, int y, int z) {
	int count = 23;
	for (int i = 0; i < count; i++) {
		BlockID block1 = createSlab(SlabType(i + 1));
		BlockID block2 = createSlab(SlabType(i + 1), SLAB_UPPER);
		BlockID block3 = createSlab(SlabType(i + 1), SLAB_DOUBLE);

		locateSlab(block1, x, y, z + 2 * i + 1);
		locateSlab(block2, x - 1, y, z + 2 * i + 1);
		locateSlab(block3, x, y, z + 2 * i);
	}
}

void testTerracotta(int x, int y, int z) {
	int count = 16;
	for (int i = 0; i < count; i++) {
		BlockID block = createTerracotta(TERRACOTTA, BlockColor(i));
		locateTerracotta(block, x, y, z + 2 * i + 1);
	}


	for (int i = 0; i < count; i++) {
		BlockID block = createTerracotta(TERRACOTTA_GLAZED, BlockColor(i));
		locateTerracotta(block, x, y, z + 2 * i);
	}
}

void testShulkerBox(int x, int y, int z) {
	int count = 16;
	for (int i = 0; i < count; i++) {
		BlockID block = createShulkerBox(BlockColor(i));
		locateShulkerBox(block, x, y, z + 2 * i + 1);
	}
}

void testWool(int x, int y, int z) {

	int count = 16;
	for (int i = 0; i < count; i++) {
		BlockID block = createWool(BlockColor(i));
		locateWool(block, x, y, z + 2 * i + 1);
	}
}

void testCarpet(int x, int y, int z) {

	int count = 16;
	for (int i = 0; i < count; i++) {
		BlockID block = createCarpet(BlockColor(i));
		locateCarpet(block, x, y, z + 2 * i + 1);
	}
}

void testSign(int x, int y, int z) {
	BlockID block = createSign(SignType(SIGN_STANDING), "1st line", "2nd line", "3rd line", "4th line");
	int count = 16;
	for (int i = 0; i < count; i++) {
		installSign(block, x, y, z + 2 * i + 1, BlockOrientation(i));
	}
}

void testBanner(int x, int y, int z) {
	int count = 16;		// for all colors and orientations
	for (int i = 0; i < count; i++) {
		int banner = createBanner(BANNER_STANDING, "", BlockColor(i));
		addPatternToBanner(banner, BlockColor((i + 1) % 16), "flo");
		installBanner(banner, x, y, z + 2 * i + 1, BlockOrientation(i));
	}
}

void testTorch(int x, int y, int z) {
	int stone = createBlock(BLOCK_STONE);
	TorchID torch = createTorch();

	locateBlock(stone, x + 1, y, z + 1);
	installTorch(torch, x + 1, y + 1, z + 1, FACING_UP);

	int count = 5;
	for (int i = 0; i < count; i++) {
		locateBlock(stone, x + 2, y + i, z + 2);

		installTorch(torch, x + 1, y + i, z + 2, FACING_WEST);
		installTorch(torch, x + 3, y + i, z + 2, FACING_EAST);
		installTorch(torch, x + 2, y + i, z + 1, FACING_NORTH);
		installTorch(torch, x + 2, y + i, z + 3, FACING_SOUTH);
	}
}

void testLadder(int x, int y, int z) {
	int stone = createBlock(BLOCK_STONE);
	int ladder = createLadder();

	int count = 5;
	for (int i = 0; i < count; i++) {
		locateBlock(stone, x + 2, y + i, z + 2);
		installLadder(ladder, x + 1, y + i, z + 2, FACING_WEST);
		installLadder(ladder, x + 3, y + i, z + 2, FACING_EAST);
		installLadder(ladder, x + 2, y + i, z + 1, FACING_NORTH);
		installLadder(ladder, x + 2, y + i, z + 3, FACING_SOUTH);
	}
}

void testRail(int x, int y, int z) {
	int rail = createRail(RAIL);
	int count = 5;

	installRail(rail, x + 1, y, z + 1, RAIL_CONNECTING_SOUTH_EAST);
	for (int i = 1; i < count; i++) {
		installRail(rail, x + i + 1, y, z + 1, RAIL_CONNECTING_EAST_WEST);
	}

	installRail(rail, x + count + 1, y, z + 1, RAIL_CONNECTING_SOUTH_WEST);
	for (int i = 1; i < count; i++) {
		installRail(rail, x + count + 1, y, z + i + 1, RAIL_CONNECTING_NORTH_SOUTH);
	}

	installRail(rail, x + count + 1, y, z + count + 1, RAIL_CONNECTING_NORTH_WEST);
	for (int i = 1; i < count; i++) {
		installRail(rail, x + count - i + 1, y, z + count + 1, RAIL_CONNECTING_EAST_WEST);
	}

	installRail(rail, x + 1, y, z + count + 1, RAIL_CONNECTING_NORTH_EAST);
	for (int i = 1; i < count; i++) {
		installRail(rail, x + 1, y, z + count - i + 1, RAIL_CONNECTING_NORTH_SOUTH);
	}
}

void testPressurePlate(int x, int y, int z) {
	int count = 4;

	for (int i = 0; i < count; i++) {
		PressurePlateID block = createPressurePlate(PressurePlateType(i + 1));
		locatePressurePlate(block, x, y, z + 2 * i + 1);
	}

}

void testButton(int x, int y, int z) {
	BlockID stone = createBlock(BLOCK_STONE);
	locateBlock(stone, x, y + 4, z);

	ButtonID btn1 = createButton(BUTTON_STONE);
	installButton(btn1, x, y + 3, z, FACING_DOWN);
	installButton(btn1, x, y + 5, z, FACING_UP);
	installButton(btn1, x + 1, y + 4, z, FACING_EAST);
	installButton(btn1, x - 1, y + 4, z, FACING_WEST);
	installButton(btn1, x, y + 4, z - 1, FACING_NORTH);
	installBanner(btn1, x, y + 4, z + 1, FACING_SOUTH);

	z += 5;

	PlanksID oak = createPlanks(PLANKS_OAK);
	locatePlanks(oak, x, y + 4, z);

	ButtonID btn2 = createButton(BUTTON_WOOD);
	installButton(btn2, x, y + 3, z, FACING_DOWN);
	installButton(btn2, x, y + 5, z, FACING_UP);
	installButton(btn2, x + 1, y + 4, z, FACING_EAST);
	installButton(btn2, x - 1, y + 4, z, FACING_WEST);
	installButton(btn2, x, y + 4, z - 1, FACING_NORTH);
	installBanner(btn2, x, y + 4, z + 1, FACING_SOUTH);
}

void testConcrete(int x, int y, int z) {
	int count = 16;
	for (int i = 0; i < count; i++) {
		BlockID block1 = createConcrete(BlockColor(i));
		BlockID block2 = createConcrete(BlockColor(i), true);
		locateConcrete(block1, x, y, z + 2 * i + 1);
		locateConcrete(block2, x + 1, y, z + 2 * i + 1);
	}
}

void testAnvil(int x, int y, int z) {
	BlockOrientation orientations[4] = { FACING_EAST, FACING_WEST, FACING_SOUTH, FACING_NORTH };	int count = 12;

	for (int i = 0; i < count; i++) {
		BlockID block = createAnvil(i % 3);
		installAnvil(block, x, y, z + 2 * i + 1, orientations[i % 4]);
	}
}

void testPlant(int x, int y, int z) {
	int count = 26;
	for (int i = 0; i < count; i++) {
		BlockID block = createPlant(PlantType(i + 1));
		locatePlant(block, x, y, z + 2 * i + 1);
	}
}

void testWater(int x, int y, int z) {
	BlockID stone = createBlock(BLOCK_STONE);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++)
			locateBlock(stone, x + i, y, z + j);
	}
	BlockID water1 = createWater();
	BlockID water2 = createWater(true);
	locateWater(water1, x + 1, y, z + 1);
	locateWater(water2, x + 1, y, z + 3);
}

void testBed(int x, int y, int z) {
	BedID bed = createBed();
	installBed(bed, x, y, z, FACING_EAST);
	installBed(bed, x, y, z + 3, FACING_WEST);
	installBed(bed, x, y, z + 6, FACING_NORTH);
	installBed(bed, x, y, z + 9, FACING_SOUTH);

}

void testBookShelf(int x, int y, int z) {
	locateBookshelf(createBookshelf(), x, y, z);
}

void testBeacon(int x, int y, int z) {
	locateBeacon(createBeacon(), x, y, z);
}

void testBarrier(int x, int y, int z) {
	locateBarrier(createBarrier(), x, y, z);
}

void testBrewingStand(int x, int y, int z) {
	locateBrewingStand(createBrewingStand(), x, y, z);
}

void testCake(int x, int y, int z) {
	int eaten = 7;
	for (int i = 0; i < eaten; i++) {
		locateCake(createCake(i), x, y, z + i);
	}
}

void testIce(int x, int y, int z) {
	int type = 3;
	for (int i = 0; i < type; i++) {
		locateIce(createIce(IceType(i)), x, y, z + i);
	}
}

void testLava(int x, int y, int z) {
	BlockID stone = createBlock(BLOCK_STONE);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++)
			locateBlock(stone, x + i, y, z + j);
	}
	BlockID lava1 = createLava();
	BlockID lava2 = createLava(true);
	locateWater(lava1, x + 1, y, z + 1);
	locateWater(lava2, x + 1, y, z + 3);
}

void testPumpkin(int x, int y, int z) {
	PumpkinID pumpkin = createPumpkin();
	installPumpkin(pumpkin, x, y, z, FACING_EAST);
	installPumpkin(pumpkin, x, y, z + 2, FACING_WEST);
	installPumpkin(pumpkin, x, y, z + 4, FACING_NORTH);
	installPumpkin(pumpkin, x, y, z + 6, FACING_SOUTH);

}

void testSnow(int x, int y, int z) {
	for (int i = 0; i < 8; i++)
		locateSnow(createSnow(i), x, y, z + i);
}

void testCauldron(int x, int y, int z) {
	int full = 4;
	for (int i = 0; i < full; i++) {
		locateCauldron(createCauldron(i), x, y, z + i);
	}
}

void testTables(int x, int y, int z) {
	locateCraftingTable(createCraftingTable(), x, y, z);
	locateEnchantingTable(createEnchantingTable(), x, y, z + 3);
}


void testFlowerPot(int x, int y, int z) {
	int type = 14;
	for (int i = 0; i < type; i++) {
		FlowerPotID pot = createFlowerPot(FlowerPotType(i + 1));
		locateFlowerPot(pot, x, y, z + i);
	}
}

void testFurnace(int x, int y, int z) {
	FurnaceID furnace = createFurnace();
	installFurnace(furnace, x, y, z, FACING_NORTH);
	installFurnace(furnace, x, y, z + 2, FACING_SOUTH);
	installFurnace(furnace, x, y, z + 4, FACING_EAST);
	installFurnace(furnace, x, y, z + 6, FACING_WEST);
}

void testLanterns(int x, int y, int z) {
	JackOLanternID j = createJackOLantern();
	installJackOLantern(j, x, y, z, FACING_NORTH);
	installJackOLantern(j, x, y, z + 2, FACING_SOUTH);
	installJackOLantern(j, x, y, z + 4, FACING_EAST);
	installJackOLantern(j, x, y, z + 6, FACING_WEST);

	SeaLanternID s = createSeaLantern();
	locateSeaLantern(s, x, y, z + 8);
}

void testLever(int x, int y, int z) {
	BlockID stone = createBlock(BLOCK_STONE);
	LeverID lever = createLever();

	for (int i = 0; i < 6; i++)
		locateBlock(stone, x, y + 3, z + 2 * i);

	installLever(lever, x, y + 4, z, FACING_UP);
	installLever(lever, x, y + 2, z + 2, FACING_DOWN);
	installLever(lever, x + 1, y + 3, z + 4, FACING_EAST);
	installLever(lever, x, y + 3, z + 7, FACING_SOUTH);
	installLever(lever, x - 1, y + 3, z + 8, FACING_WEST);
	installLever(lever, x, y + 3, z + 9, FACING_NORTH);
}

void testSponge(int x, int y, int z) {
	locateSponge(createSponge(), x, y, z);
}


#define TEST(f)		test ## f (px + x, py, pz); x += 5

int main() {
	int px, py, pz, x = 5;
	getPlayerLocation(&px, &py, &pz);

	TEST(Block);
	TEST(Ore);
	TEST(Bricks);
	TEST(Planks);
	TEST(Wood);
	TEST(Stairs);
	TEST(Door);
	TEST(Fence);
	TEST(Pane);
	TEST(Flower);
	TEST(Slab);
	TEST(Terracotta);
	TEST(ShulkerBox);
	TEST(Wool);
	TEST(Carpet);
	TEST(Banner);
	TEST(Torch);
	TEST(Ladder);
	TEST(Rail); x += 5;
	TEST(PressurePlate);
	TEST(Button);
	TEST(Concrete);
	TEST(Anvil);
	TEST(Plant);
	TEST(Water);
	TEST(Bed);
	TEST(Beacon);
	TEST(Barrier);
	TEST(BookShelf);
	TEST(BrewingStand);
	TEST(Cake);
	TEST(Ice);
	TEST(Lava);
	TEST(Pumpkin);
	TEST(Snow);
	TEST(Cauldron);
	TEST(Tables);
	TEST(FlowerPot);
	TEST(Furnace);
	TEST(Lanterns);
	TEST(Lever);
	TEST(Sponge);
}


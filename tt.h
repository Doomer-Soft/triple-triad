const char* ASSET_PATH = "assets/cards/";
const char* CARD_NAMES[] = {"Abadon-Card.png", "Abyss-Worm.png", "Adamantoise-Card.png", "Alexander-Card.png", "Anacondaur-Card.png", "Angelo-Card.png", "Armadodo-Card.png", "BGH251F2-Card.png", "Bahamut-Card.png", "Behemoth-Card.png", "Belhelmel-Card.png", "Biggs,-Wedge-Card.png", "Bite-Bug-Card.png", "Blitz-Card.png", "Blobra-Card.png", "Blood-Soul-Card.png", "Blue-Dragon-Card.png", "Bomb-Card.png", "Buel-Card.png", "Cactuar-Card.png", "Carbuncle-Card.png", "Caterchipillar-Card.png", "Catoblepas-Card.png", "Cerberus-Card.png", "Chicobo-Card.png", "Chimera-Card.png", "Chubby-Chocobo-Card.png", "Cockatrice-Card.png", "Creeps-Card.png", "Death-Claw-Card.png", "Diablos-Card.png", "Doomtrain-Card.png", "Edea-Card.png", "Eden-Card.png", "Elastoid-Card.png", "Elnoyle-Card.png", "Elvoret-Card.png", "Fastitocalon-Card.png", "Fastitocalon-F-Card.png", "Forbidden-Card.png", "Fujin,-Raijin-Card.png", "Funguar-Card.png", "GIM47N-Card.png", "Gargantua-Card.png", "Gayla-Card.png", "Geezard-Card.png", "Gerogero-Card.png", "Gesper-Card.png", "Gilgamesh-Card.png", "Glacial-Eye-Card.png", "Granaldo-Card.png", "Grand-Mantis-Card.png", "Grat-Card.png", "Grendel-Card.png", "Hexadragon-Card.png", "Ifrit-Card.png", "Iguion-Card.png", "Imp-Card.png", "Iron-Giant-Card.png", "Irvine-Card.png", "Jelleye-Card.png", "Jumbo-Cactuar-Card.png", "Kiros-Card.png", "Krysta-Card.png", "Laguna-Card.png", "Leviathan-Card.png", "Malboro-Card.png", "Mesmerize-Card.png", "MiniMog-Card.png", "Minotaur-Card.png", "Mobile-Type-8-Card.png", "Ochu-Card.png", "Odin-Card.png", "Oilboyle-Card.png", "Pandemona-Card.png", "Phoenix-Card.png", "Propagator-Card.png", "PuPu-Card.png", "Quezacotl-Card.png", "Quistis-Card.png", "Red-Bat-Card.png", "Red-Giant-Card.png", "Rinoa-Card.png", "Ruby-Dragon-Card.png", "SAM08G-Card.png", "Sacred-Card.png", "Seifer-Card.png", "Selphie-Card.png", "Shiva-Card.png", "Shumi-Tribe-Card.png", "Siren-Card.png", "Snow-Lion-Card.png", "Sphinxara-Card.png", "Squall-Card.png", "T-Rexaur-Card.png", "Thrustaevis-Card.png", "Tiamat-Card.png", "Tonberry-Card.png", "Tonberry-King-Card.png", "Torama-Card.png", "Trauma-Card.png", "Tri-Face-Card.png", "Tri-Point-Card.png", "Turtapod-Card.png", "Ultima-Weapon-Card.png", "Vysage-Card.png", "Ward-Card.png", "Wendigo-Card.png", "X-ATM092-Card.png", "Zell-Card.png"};
const int CARD_NUMBER = 110;

struct Board {
	int cards_drawn;
	SDL_Rect** rectangles;

};

typedef struct Board Board;

struct Mouse {
	int x;
	int y;
};

typedef struct Mouse Mouse;

struct Sprite {
	char* name;
	int x;
	int y;
	int w;
	int h;
	int points[4];
	int dragging;
	int isRendered;
	SDL_Texture* tex;
};

typedef struct Sprite Sprite;


Sprite* 	new_sprite(char*, char*);
SDL_Rect* create_rect(int);
void 			load_assets();
void			init_game();


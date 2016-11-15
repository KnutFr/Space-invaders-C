#include "stdafx.h"
#include "time.h"
#include "string.h"
#include "math.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/fmod.h>

#define SCREEN_WIDTH			700
#define SCREEN_HEIGHT			700
#define SCREEN_BITBYPIXEL		32
#define FIRE_SHIFTX				2
#define FIRE_SHIFTY				2
#define SHIP_WIDTH				26
#define SHIP_HEIGHT				32
#define INV_ROW					5
#define INV_COL					10
#define INV_TOP					70
#define INV_LEFT				160
#define INV_SHIFT				40
#define INV_DELAY				200
#define INV_HEIGHT				16
#define INV_WIDTH				24
#define BORDER					5
#define SHOOT_HEIGHT			8
#define SHOOT_WIDTH				3
#define MOVE_SHIP				6
#define MOVE_SHOOT				12
#define MOVE_INVX				2
#define MOVE_INVY				10
#define MOVE_BLOCK				6
#define LINE_Y					550
#define BLOCK_TOP				570
#define BLOCK_LEFT				100			
#define BLOCK_SHIFT				150
#define BLOCK_WIDTH				50
#define BLOCK_HEIGHT			20
#define EXPLOSION_WIDTH			28
#define PATH_SHIP_SHOOT			"resources/img/shipshoot.bmp"
#define PATH_BG_GAME			"resources/img/background.png"
#define PATH_BG_GAME2			"resources/img/background2.png"
#define PATH_BG_MENU			"resources/img/background-menu.jpg"
#define PATH_GAMEOVER			"resources/img/gameover.png"
#define PATH_LINE				"resources/img/line.png"
#define PATH_ICON				"resources/img/icon.png"
#define PATH_EXPLOSION			"resources/img/explosion.png"
#define PATH_INV_SHOOT			"resources/img/invadershoot.bmp"
#define PATH_INV_1A				"resources/img/invader1A.png"
#define PATH_INV_1B				"resources/img/invader1B.png"
#define PATH_INV_2A				"resources/img/invader2A.png"
#define PATH_INV_2B				"resources/img/invader2B.png"
#define PATH_INV_3A				"resources/img/invader3A.png"
#define PATH_INV_3B				"resources/img/invader3B.png"
#define PATH_BLOCK1				"resources/img/block1.png"
#define PATH_BLOCK2				"resources/img/block2.png"
#define PATH_BLOCK3				"resources/img/block3.png"
#define PATH_SHIP1				"resources/img/ship1.png" 
#define PATH_SHIP2				"resources/img/ship2.png"
#define PATH_SHIP3				"resources/img/ship3.png"
#define PATH_SHIP4				"resources/img/ship4.png"
#define PATH_NONE				"resources/img/NONE.png"
#define PATH_PIC_AST			"resources/img/stefan_a.jpg"
#define PATH_PIC_MPA			"resources/img/papand_m.jpg"
#define PATH_PIC_RTO			"resources/img/toppan_r.jpg"
#define PATH_PATH_ICON			"resources/img/icon.png"
#define PATH_HSCORE				"resources/txt/highscore.txt"
#define PATH_RENEGADE			"resources/font/Renegade.ttf"
#define PATH_OPTIMUS			"resources/font/Optimus.ttf"
#define PATH_VISITOR			"resources/font/visitor.ttf"
#define PATH_BODY				"resources/img/body.png"
#define PATH_LEFT_ARM1			"resources/img/normal_left_arm.png"
#define PATH_LEFT_ARM2			"resources/img/opened_left_arm.png"
#define PATH_LEFT_ARM3			"resources/img/closed_left_arm.png"
#define PATH_RIGHT_ARM1			"resources/img/normal_right_arm.png"
#define PATH_RIGHT_ARM2			"resources/img/opened_right_arm.png"
#define PATH_RIGHT_ARM3			"resources/img/closed_right_arm.png"
#define PATH_HEART1				"resources/img/normal_heart.png"
#define PATH_HEART2				"resources/img/red_heart.png"
#define PATH_HEART3				"resources/img/dark_purple_heart.png"
#define PATH_HEART4				"resources/img/light_purple_heart.png"
#define PATH_FIREBALL1			"resources/img/fireball_1.png"
#define PATH_FIREBALL2			"resources/img/fireball_2.png"
#define PATH_FIREBALL3			"resources/img/fireball_3.png"
#define PATH_FIREBALL4			"resources/img/fireball_4.png"
#define PATH_CHARGING_LASER1	"resources/img/loading_laser_1.png"
#define PATH_CHARGING_LASER2	"resources/img/loading_laser_2.png"
#define PATH_LASER				"resources/img/laser.jpg"
#define PATH_SPECIAL_LASER1		"resources/img/special_laser1.png"
#define PATH_SPECIAL_LASER2		"resources/img/special_laser2.png"
#define AST						"Adrien STEFANSKI"
#define MPA						"Marine PAPANDREOU"
#define RTO						"Robin TOPPAN"
#define PWD_LVL1				"one"
#define PWD_LVL2				"two"
#define PWD_LVL3				"three"
#define PWD_LVL4				"four"
#define SCREEN_TITLE			"Space Invaders"

struct s_home
{
	int itemsX[6];
	int nbItems;
	int posItems;
	char *items[6];
	SDL_Surface *itemFont[6];
	SDL_Rect itemRect[6];
};

struct s_ship
{
	int itemsX[5];
	int nbItems;
	int posItems;
	char *items[5];
	int PictRectX[5];
	SDL_Surface *itemFont[5];
	SDL_Surface *PictShip[5];
	SDL_Rect itemRect[5];
	SDL_Rect PictRect[5];
};

struct s_level
{
	int itemsX[2];
	int LabelcodeX;
	int flag;
	int nbkeycode;
	char *labelcode;
	char entcode[5];
	char *code[5];
	int nbItems;
	char *items[2];
	int posItems;
	int ValidLev;
	SDL_Surface *labelcodeFont;
	SDL_Rect labelcodeRect;
	SDL_Surface *itemFont[2];
	SDL_Rect itemRect[2];
};

struct s_writescore                            
{
	int itemsX[2];
	int LabelnameX;
	int flag;
	int nbkeycode;
	char *labelname;
	char entname[5];
	char *name[5];
	int nbItems;
	char *items[2];
	int posItems;
	int ValidLev;
	SDL_Surface *labelnameFont;
	SDL_Rect labelnameRect;
	SDL_Surface *itemFont[2];
	SDL_Rect itemRect[2];
};

struct s_changeLevel
{
	int itemsX[2];
	char *items[2];
	int NbItems;
	SDL_Surface *itemFont[2];
	SDL_Rect itemRect[2];
};

struct s_highscore
{
	 char name[5];
	 char score[5];
};

struct s_life
{
	TTF_Font *font;

	SDL_Rect msgRect;
	SDL_Rect lifeRect;

	SDL_Surface *msg;
	SDL_Surface *life;

	SDL_Color msgColor;
	SDL_Color lifeColor;
};

struct s_score
{
	int itemsX[5];
	char *itemsRank[5];
	char *items[5];
	char *itemsSc[5];
	int itemsRkX[5];
	int itemsScX[5];
	int nbItems;
	int posItems;
	SDL_Surface *itemRkFont[5];
	SDL_Rect itemRkRect[5];
	SDL_Surface *itemScFont[5];
	SDL_Rect itemScRect[5];
	SDL_Surface *itemFont[5];
	SDL_Rect itemRect[5];
};

struct s_option
{
	int itemsX[3];
	char *optval[3];
	int nbItems;
	int posItems;
	char *items[3];
	SDL_Surface *itemFont[3];
	SDL_Rect itemRect[3];
	SDL_Surface *valFont[3];
	SDL_Rect optValRect[3] ;
};

struct s_credit
{
	int itemsX[5]; 
	int NbItems;
	int PosItems;
	char *Items[5];
	int PictRectX [5];
	SDL_Surface *itemFont[5];
	SDL_Surface *Pict[5];
	SDL_Rect itemRect[5];
	SDL_Rect PictRect[5];
};

struct s_timer
{
	Uint32 now;
	Uint32 last;
};

struct s_background
{
	SDL_Surface *img1;
	SDL_Surface *img2;
	SDL_Rect rect;
};

struct s_gameShip
{
	SDL_Surface *img;
	SDL_Rect rect;
	struct s_timer destroyedTimer;
	struct s_timer blinkingTimer;
	int life;
	int oldLife;
};

struct s_shoot
{
	SDL_Surface *img1;
	SDL_Surface *img2;
	SDL_Rect rect;
	int exist;
};

struct s_invader
{
	SDL_Surface *img1;
	SDL_Surface *img2;
	SDL_Rect rect;
	int life;
	int score;
	struct s_shoot shoot;
};

struct s_position {
	short stepNb;
	short speed;
	float speedCoef;
	float x;
	float y;
	float nextX;
	float nextY;
	float stepX;
	float stepY;
};

struct s_fireball {
	SDL_Surface *fb[4];
	SDL_Rect fbRect;
	struct s_timer spriteTimer;
	short spriteNb;
	float stepX;
	float stepY;
};

struct s_laser {
	SDL_Surface *ball[2];
	SDL_Surface *laser[3];
	SDL_Rect ballRect[2];
	SDL_Rect laserRect[2];
	struct s_timer spriteTimer;
	short ballSpriteNb;
	short laserSpriteNb;
};

struct s_boss {
	SDL_Surface *elts[4][4];
	SDL_Rect eltsRects[4];
	struct s_position pos;
	struct s_fireball fb;
	struct s_laser laser;
	struct s_timer atkTimer;
	struct s_life life;
	short health;
	short oldhealth;
	short leftArm;
	short rightArm;
	short heart;
	short moving;
	short attacking;
	short atkNb;
};

struct s_gameScore
{
	int value;
	TTF_Font *font;

	SDL_Rect msgRect;
	SDL_Rect scoreRect;
	SDL_Rect titleRect;

	SDL_Surface *msg;
	SDL_Surface *score;
	SDL_Surface *title;

	SDL_Color msgColor;
	SDL_Color scoreColor;
};

struct s_line
{
	SDL_Surface *img;
	SDL_Rect rect;
};

struct s_block
{
	SDL_Surface *img1;
	SDL_Surface *img2;
	SDL_Surface *img3;
	SDL_Rect rect;
	int life;
};

struct s_index
{
	int X;
	int Y;
};

struct s_game
{
	struct s_background bg;
	struct s_gameShip ship;
	struct s_shoot shoot;
	struct s_invader inv[INV_ROW][INV_COL];
	struct s_boss boss;
	struct s_gameScore score;
	struct s_gameScore gameover;
	struct s_life life;
	struct s_line line;
	struct s_block block[4];

	int music;
	int effect;
	int level;
	int switcher;
	int direction;
	int blockDirection;

	SDL_Surface *screen;
	SDL_Event event;

	Uint32 nowTime;
	Uint32 lastTime;
};

struct s_save
{
	int i_score;
	char c_score[5];
};

struct s_menu
{
	struct s_home home;
	struct s_ship ship;
	struct s_level level;
	struct s_score score;
	struct s_option opt;
	struct s_credit credit;
	struct s_timer time;
	struct s_changeLevel chlevel;
	struct s_highscore highscore[5];
	struct s_writescore wrscore;
	struct s_save save;

	SDL_Surface *bgImg;
	SDL_Rect bgRect;
	SDL_Surface *title;
	SDL_Rect titleRect;
	TTF_Font *fontTitle;
	TTF_Font *fontItems;
	TTF_Font *fontCredit;
	SDL_Color  fontColorCredit;
	SDL_Color fontColor;
	SDL_Color fontColorSelect;
	Uint32 nowTime;
	Uint32 lastTime;
	int count;
	int posMenu;
};

typedef struct s_index t_index;
typedef struct s_invader t_invader;
typedef struct s_boss t_boss;
typedef struct s_game t_game;
typedef struct s_menu t_menu;

// AttackFire.c
void Fire(t_game *g);
void InvFire(t_invader *i);
void CheckForemostInv(t_game *g, int i, int j);
void GenerateFire(t_game *g, t_index *f);

//BossAttacks.c
void Fireball(t_game *g);
void Laser(t_game *g);
void Charge(t_game *g);
void SpecialAttack(t_boss *g);

//BossAttacksTools1.c
void SetAndInitAttack(t_boss *boss);
void SelectFireballSprite(struct s_fireball *fb);
void SetFireballInitialPostion(t_boss *boss);
void MoveFireball(t_game *g);
void SetLaserEltsPostions(t_boss *boss, short offset);
//BossAttacksTools2.c
void SelectLaserBallSprite(struct s_laser *laser);
void SelectLaserSprite(struct s_laser *laser);
void GetChargeSteps(t_game *g, short flag);
void SpecialAttackMoves(t_game *g);

// BossTools.c
void SetArmsAndHeart(t_boss *boss, short leftArm, short rightArm, short heart);
void SetEltsPositions(t_boss *boss);
void prepareDynamicAttack(t_boss *boss);
void finishDynamicAttack(t_boss *boss);
void setScoreAndBossHealth(t_game *g, short pointsWon, short bossHealthLost);

// BrowserMenu.c
void BrowserMenuHome(t_menu *m, t_game *g);
void BrowserMenuShip(t_menu *m, t_game *g);
void BrowserMenuLevel(t_menu *m, t_game *g);
void BrowserMenuOpt(t_menu *m, t_game *g);

// ChangeOpt.c
void ChangeOpt(t_menu *m, t_game *g);

// CheckCollisions1.c
void CheckShipShoot(t_game *g);
void CheckInvShootsWithShipShoot(t_game *g, int i, int j);
void CheckInvShootsWithShip(t_game *g);
void CheckCollisions(t_game *g);
void CheckShipShootWithBlocks(t_game *g);
// CheckCollisions2.c
void CheckInvShootsWithBlock(t_game *g, int i, int j);
void CheckShipWithBoss(t_game *g);
int CheckArm(t_game *g, short armIndicator, short coeff);
int xPosShootChecker(t_game *g, short x1, short x2);
int yPosShootChecker(t_game *g, short x1, short x2);

// CheckCollisions3.c
void FireballCollision(t_game *g);
void LaserCollision(t_game *g);
void ChargeCollision(t_game *g);

// FileScore.c
void FileScoreRead(t_menu *m);

// Game.c
void StartGame(t_menu *m, t_game *g);
void LoadLevel(t_menu *m, t_game *g);
void ReloadGame(t_game *g);

// GameDyamic1.c
void MoveDownInvaders( t_game *g);
void MoveInvader(t_game *g);
int ShipReappearance(t_game *g);
int CountAliveInvaders(t_game *g);
t_index *GetAliveInvIndex(t_game *g);
// GameDyamic2.c
void MoveBlock(t_game *g);
void animateBoss (t_game *g);
void moveBoss(t_boss *boss);

// HandleKeyboard1.c
void HandleKeyboardEventsHome(t_menu *m, t_game *g, Uint8 *keystate);
void HandleKeyboardEventsShip(t_menu *m, t_game *g, Uint8 *keystate);
void HandleKeyboardEventsScore(t_menu *m, t_game *g, Uint8 *keystate);
void HandleKeyboardEventsLevel(t_menu *m, t_game *g, Uint8 *keystate);
void HandleKeyboardEventsOpt(t_menu *m, t_game *g, Uint8 *keystate);
// HandleKeyboard2.c
void HandleKeyboardEventsCredit(t_menu *m, t_game *g, Uint8 *keystate);
void HandleKeyboardEventsChangeLvl(t_menu *m, t_game *g, Uint8 *keystate);
void HandleKeyboardGame(t_game *g, Uint8 *keystate);
void HandleKeyboardEvents(t_menu *m, t_game *g);
void HandleKeyboardEventsWrScore(t_menu *m, t_game *g, Uint8 *keystate);

// Levelcode.c
void Levelcode (t_menu *m, t_game *g);
void Levelcodecmp(t_menu *m, t_game *g);
void LevelCodeinit(t_menu *m);

//FileScore.c
void FileScoreRead(t_menu *m);
void FileScore_write(t_menu *m);
void FileScore_cast(t_menu *m);
void FileScore_sort(t_menu *m);
void FileScoreWrite(t_menu *m, t_game *g);

// Load.c
void LoadGame(t_game *g);
void LoadProperties(t_menu *m);
void LoadMenu(t_menu *m);
void LoadMenuItems(t_menu *m);
void LoadComponents(t_menu *m, t_game *g);

// LoadMenu1.c
void LoadMenuHome(t_menu *m);
void LoadMenuLevel(t_menu *m);
void LoadMenuScore(t_menu *m);
void LoadMenuOpt(t_menu *m);
void LoadMenuShip(t_menu *m);
// LoadMenu2.c
void LoadMenuCredit(t_menu *m);
void LoadMenuChangeLev(t_menu *m, char *level, char *pass);
void LoadMenuWrScore(t_menu *m);

// LoadGame1.c
void LoadBackground(t_game *g);
void LoadFire(t_game *g);
void LoadShip(t_game *g);
void LoadScore(t_game *g);
void LoadLives(t_game *g);
// LoadGame2.c
void LoadGameOver(t_game *g);
int LoadInvScore(int i);
void LoadInvPaths(int i, char **p1, char **p2, SDL_Surface **l1, SDL_Surface **l2);
void LoadInvaders(t_game *g);
SDL_Surface *MyIMG_Load(char *path, SDL_Surface *dst);
// LoadGame3.c
void LoadInvader(t_game *g, t_index t, SDL_Surface **loader, SDL_Surface **loadfire);
void LoadLine(t_game *g);
void LoadBlocks(t_game *g);
void LoadBoss(t_game *g);
void LoadBossSprites(t_game *g);
void LoadBossHealth(t_game *g);
// LoadGame4.c
void LoadBossHealth(t_game *g);

// LoadMenuItems1.c
void LoadItemsHome(t_menu *m);
void LoadItemsShip(t_menu *m);
void LoadItemsLevel(t_menu *m);
void LoadItemsScore(t_menu *m);
void LoadItemsOpt(t_menu *m);
// LoadMenuItems2.c
void LoadItemsCredit(t_menu *m);
void LoadItemsChangeLev(t_menu *m);
void LoadItemsWrScore(t_menu *m);

// main.c
int main (int argc, char **argv);
void InitAll(t_menu *m, t_game *g);
void FreeAll(t_menu *m, t_game *g);

// ShowGame1.c
void ShowGame(t_game *g);
void ShowAnimatedInvaders(t_game *g);
void ShowInvShots(t_game *g);
void ShowGameOver(t_game *g);
void ShowGameShip(t_game *g);
// ShowGame2.c
void ShowBlocks(t_game *g);
void ShowBoss(t_game *g);
void ShowBossLevelTxt(t_game *g);
void ShowBossAtk(t_game *g);
void ShowBackground(t_game *g);

// ShowMenu1.c
void ShowHome(t_menu *m, t_game *g);
void ShowShip(t_menu *m, t_game *g);
void ShowLevel(t_menu *m, t_game *g);
void ShowScore(t_menu *m, t_game *g);
void ShowOpt(t_menu *m, t_game *g);
// ShowMenu2.c
void ShowCredit(t_menu *m, t_game *g);
void ShowChangeLevel(t_menu *m, t_game *g);
void ShowComponents(t_menu *m, t_game *g);
void ShowWrScore(t_menu *m, t_game *g);

//Sound.c
FMOD_SYSTEM *sys;
FMOD_SOUND *musique;

int 	playmusic(char *mySound);
int 	playsound(char *mySound);
void 	init_sound();


//WrScore.c
void WrScoreName(t_menu *m, t_game *g, Uint8 *keystate);
void WrScoreNameInit(t_menu *m);
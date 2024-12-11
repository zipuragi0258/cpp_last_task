#include <iostream>
#include <string>

#include "state.h"
#include "screen_printing.h"
#include "module.h"
#include "Gamelog.h"
#include "Player.h"
#include "Monster.h"

Player player("name", 200, 10);

int main()
{
    int unlocked_stage = 1;
    int stage_select;
    bool clearPara = false;

    string answer;
    nowPlace = BEFORE_GAME;
    Gamelog gamelog
    (
        "(A) Welcome To JunHa's Adventure!",
        "(A) 모든 선택은 커맨드로 진행합니다.",
        "(A) 게임을 진행하며 로그는 여기 적힙니다.",
        "(A) Enter를 눌러 시작하세요."
    );

    print_start_screen();
    gamelog.print_log();

    cin.get();

    gamelog.add_log("(A) 캐릭터를 선택하세요.");
    change_state(INIT_GAME);
    screen_reload();
    gamelog.print_log();

    string player_character = get_answer(gamelog);

    print_string("\"아...\"\n");
    gamelog.add_log("(A) enter를 눌러 계속...");
    gamelog.print_log();
    cin.get();

    print_string("\"모오 콘나 진세이 야다..!!\"\n");
    gamelog.print_log();
    cin.get();

    print_string("욱하고 내딛인 발걸음에 더는 돌이킬 수 없는\n        상황이 펼쳐지고 말았다.");
    gamelog.print_log();
    cin.get();

    print_string("\"이렇게 끝나는 구나...\n        상처로 가득한 인생이었어\"");
    gamelog.print_log();
    cin.get();

    print_string("\"하지만...\"\n");
    gamelog.print_log();
    cin.get();

    print_string("\"아직 더 살고싶어..!!\"\n");
    gamelog.print_log();
    cin.get();

    print_string("시간이 천천히 흘러가고\n        눈에 보이는 것들이 구분가지 않는다.");
    gamelog.print_log();
    cin.get();

    print_string("밝은 빛이 나를 덮어온다.\n        이게 죽음을 맞이한다는 것일까.");
    gamelog.print_log();
    cin.get();

    print_string("...\n");
    gamelog.print_log();
    cin.get();

    print_string("......\n");
    gamelog.print_log();
    cin.get();

    print_string("\"용사여, 정신이 드는가\"\n");
    gamelog.print_log();
    cin.get();

    print_string("\"용..사...? 여긴 어디지?\"\n");
    gamelog.print_log();
    cin.get();

    print_string("\"이곳은 자네가 살던 세상이 아니라네.\n        자네는 우리에게 소환당한 것이네.\"");
    gamelog.print_log();
    cin.get();

    print_string("\"그.. 말은.. 제가 이세계로 왔다는 것인가요..?\"\n");
    gamelog.print_log();
    cin.get();

    print_string("\"그렇다네. 자네는 이쪽 세계를 위해 힘써줘야겠어.\"\n");
    gamelog.print_log();
    cin.get();

    print_string("\"뭔지는 모르겠지만 열심히 살겠습니다\"\n");
    gamelog.print_log();
    cin.get();

    print_string("\"받아드리는게 빨라 좋군.\n        그건 그렇고 자네 이름이 뭔가?\"");
    gamelog.print_log();
    cin.get();

    print_string("\"받아드리는게 빨라 좋군.\n        그건 그렇고 자네 이름이 뭔가?\"");
    gamelog.add_log("(A) 당신의 이름은 무엇입니까?");
    gamelog.print_log();
    cin >> answer;
    gamelog.add_log("(You) " + answer);

    player.setName(answer);

    if (player_character == "mage")
    {
        player.setHp(150);
        player.setStrength(15);
    }

    cin.get();
    gamelog.add_log("(A) enter를 눌러 계속...");
    print_string("\"오오.. 용사 " + player.getName() + "(이)여...\n        어서가서 이 세계를 위해 몬스터들을 처치해주게.\"");
    gamelog.print_log();
    cin.get();

    print_string("\"쏘카.. 나는...\n        그래! 다시 주어진 기회, 이번엔 열심히 살겠어!\"");
    gamelog.print_log();
    cin.get();

    change_state(TOWN);
    gamelog.add_log("(A) town으로 이동했습니다.");
    screen_reload();
    gamelog.print_log();

    while (true)
    {
        answer = get_answer(gamelog);

        if (answer == "go shop")
        {
            change_state(SHOP);
            gamelog.add_log("(A) shop으로 이동했습니다.");
            system("cls");
            cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
            print_shop_screen();
            gamelog.print_log();
        }
        else if (answer == "go field")
        {
            change_state(FIELD);
            gamelog.add_log("(A) field로 이동했습니다.");
            system("cls");
            cout << player_character << " " << player.getName() << " Lv." << player.getLevel();
            print_field_screen();
            gamelog.print_log();
        }
        else if (answer == "get reward")
        {
            if (player.getExp() > player.getMaxExp())
            {
                player.levelUp();
                gamelog.add_log("(A) 레벨업 했습니다.");
                system("cls");
                cout << player_character << " " << player.getName() << " Lv." << player.getLevel();
                print_town_screen();
                gamelog.print_log();
            }

            if (clearPara)
            {
                player.addMoney(stage_select*5);
                gamelog.add_log("(A) " + to_string(stage_select * 5) + "골드를 획득했습니다.");
                system("cls");
                cout << player_character << " " << player.getName() << " Lv." << player.getLevel();
                print_town_screen();
                gamelog.print_log();

                clearPara = true;
            }
        }
        else if (answer == "buy item")
        {
            gamelog.add_log("(A) 어떤 아이템을 구입하시겠습니까?");
            system("cls");
            cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
            print_shop_screen();
            gamelog.print_log();

            string item;
            getline(cin, item);

            if (item == "짱센칼" && player_character == "knight")
            {
                if (player.getMoney() >= 20)
                {
                    gamelog.add_log("(A) 짱센칼을 구입했습니다.");

                    player.addMoney(-20);
                    player.addStrength(20);

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
                else
                {
                    gamelog.add_log("(A) 구매할 수 없습니다.");

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
            }
            else if (item == "튼튼한 갑옷")
            {
                if (player.getMoney() >= 50)
                {
                    gamelog.add_log("(A) 튼튼한 갑옷을 구입했습니다.");

                    player.addMoney(-50);
                    player.addArmor(20);

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
                else
                {
                    gamelog.add_log("(A) 구매할 수 없습니다.");

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
            }
            else if (item == "마법사의 반지" && player_character == "mage")
            {
                if (player.getMoney() >= 20)
                {
                    gamelog.add_log("(A) 마법사의 반지를 구입했습니다.");

                    player.addMoney(-20);
                    player.addStrength(20);

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
                else
                {
                    gamelog.add_log("(A) 구매할 수 없습니다.");

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
            }
            else if (item == "생명의 토템")
            {
                if (player.getMoney() >= 100)
                {
                    gamelog.add_log("(A) 생명의 토템을 구입했습니다.");

                    player.addMoney(-100);
                    player.addHp(100);

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
                else
                {
                    gamelog.add_log("(A) 구매할 수 없습니다.");

                    system("cls");
                    cout << player_character << " " << player.getName() << " Lv." << player.getLevel() << " money : " << player.getMoney();
                    print_shop_screen();
                    gamelog.print_log();
                }
            }
        }
        else if (answer == "sell item")
        {

        }
        else if (answer == "go town")
        {
            change_state(TOWN);
            gamelog.add_log("(A) town으로 이동했습니다.");
            system("cls");
            cout << player_character << " " << player.getName() << " Lv." << player.getLevel();
            print_town_screen();
            gamelog.print_log();
        }
        else if (answer == "select stage")
        {
            gamelog.add_log("(A) 스테이지를 선택하세요.");
            gamelog.add_log("Stage select => 1 ~ " + to_string(unlocked_stage));
            change_state(SELECT_STAGE);
            screen_reload();
            gamelog.print_log();

            while (true)
            {
                cin >> stage_select;

                if (stage_select > 0 && stage_select <= unlocked_stage)
                {
                    gamelog.add_log("(You) " + to_string(stage_select));
                    break;
                }
                else
                {
                    gamelog.add_log("(A) 선택할 수 없는 스테이지입니다.");
                    screen_reload();
                    gamelog.print_log();
                }
            }
            int playerhp = player.getHp();

            change_state(ON_FIGHTING);
            gamelog.add_log("(A) 싸움에 진입했습니다.");
            fighting(stage_select, player, answer, gamelog);

            player.setHp(playerhp);

            change_state(TOWN);
            system("cls");
            cout << player_character << " " << player.getName() << " Lv." << player.getLevel();
            print_town_screen();
            gamelog.add_log("(A) town으로 이동했습니다.");
            gamelog.print_log();

            player.addExp(5*stage_select);
            clearPara = true;
            unlocked_stage++;
        }
    }
}
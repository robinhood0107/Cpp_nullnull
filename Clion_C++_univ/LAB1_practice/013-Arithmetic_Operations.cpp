
// ??臾몄젣 fixed??setprecision ?뚭퀬?덈깘 留덈깘?? 諛섎뱶???몄슦怨?媛
// ?붿쭅??蹂댁옄留덉옄 湲곗뼲 ?덈궓 肄붾뱶 ?몄슦怨?媛??
// #include <iomanip> ?닿굅 諛섎뱶???몄썙???닿굅 紐⑤Ⅴ怨??덉뿀??

//?닿? ?由?遺遺?: setprecision <- ?곕뒗 踰뺤씠??泥좎옄 ?묐컮濡??몄썙?쇰씪, #include <iomanip> ?닿굅 諛섎뱶???몄썙??
/**/
#include <iostream>
#include <iomanip>
using namespace std;

int p013() {
    float a1;
    float a2;

    cin >> a1 >> a2;

    cout << fixed << setprecision(2) << a1 << " + " << a2 << " = " << a1 + a2 << "\n";
    cout << fixed << setprecision(2) << a1 << " - " << a2 << " = " << a1 - a2 << "\n";
    cout << fixed << setprecision(2) << a1 << " * " << a2 << " = " << a1 * a2 << "\n";
    cout << fixed << setprecision(2) << a1 << " / " << a2 << " = " << a1 / a2 << "\n";

    return 0;
}

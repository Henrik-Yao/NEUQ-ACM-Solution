#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct Lover
{
    int fatherID = -1;
    int motherID = -1;
    char gender;
} Lovers[N];
bool Inquire(int inquireida, int inquireidb, int depth)
{
    depth++;
    if (inquireida == -1 || inquireidb == -1)
    {
        return 1;
    }
    else if (((Lovers[inquireida].fatherID == Lovers[inquireidb].fatherID) && Lovers[inquireida].fatherID != -1) || ((Lovers[inquireida].motherID == Lovers[inquireidb].motherID) && Lovers[inquireidb].motherID != -1))
    { /*
        cout << "---throw----" << endl;
        cout << "a: " << inquireida << "  "
             << "b: " << inquireidb << "  "
             << "depth: " << depth << endl;
        cout << "afather: " << Lovers[inquireida].fatherID << "  "
             << "bfather: " << Lovers[inquireidb].fatherID << "  "
             << "amother: " << Lovers[inquireida].motherID << "  "
             << "bmother: " << Lovers[inquireidb].motherID << "  " << endl;
        cout << "- - - -testend- - - -" << endl;*/
        return 0;
    }
    else if (depth >= 5)
    {
        return 1;
    }
    else
    {
        return Inquire(Lovers[inquireida].fatherID, Lovers[inquireidb].fatherID, depth) && Inquire(Lovers[inquireida].motherID, Lovers[inquireidb].motherID, depth) && Inquire(Lovers[inquireida].fatherID, Lovers[inquireidb].motherID, depth) && Inquire(Lovers[inquireida].motherID, Lovers[inquireidb].fatherID, depth);
    }
}
int main()
{
    int allovers, inquirenum, cinid, inquireida, inquireidb;
    scanf("%d", &allovers);
    for (int i = 0; i < allovers; ++i)
    {
        cin >> cinid >> Lovers[cinid].gender >> Lovers[cinid].fatherID >> Lovers[cinid].motherID;
        /*        cout << "----test " << i + 1 << " ----" << endl;
        cout << cinid << "  " << Lovers[cinid].gender << "  " << Lovers[cinid].fatherID << "  " << Lovers[cinid].motherID << endl
             << "----test " << i + 1 << " end----" << endl;

             输入正常
             
             */
        if (Lovers[cinid].fatherID != -1)
        {
            Lovers[Lovers[cinid].fatherID].fatherID = 'M';
        }
        if (Lovers[cinid].motherID != -1)
        {
            Lovers[Lovers[cinid].motherID].motherID = 'F';
        }
    }
    scanf("%d", &inquirenum);
    while (inquirenum--)
    {
        scanf("%d %d", &inquireida, &inquireidb);

        if (Lovers[inquireida].gender == Lovers[inquireidb].gender)
        {
            printf("Never Mind\n");
        }
        else
        {
            if (!Inquire(inquireida, inquireidb, 1))
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
    }

    return 0;
}
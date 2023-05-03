#include <string>
#include <vector>
#include <map>

using namespace std;

class Value
{
public:
    Value(string referral, int money)
	    : referral(referral), money(money)
    {}

    void setReferral(string r) { referral = r; }
    string getReferral() { return referral; }
    void setMoney(int m) { money = m; }
    int getMoney() { return money; }

private:
    string referral;
    int money;
};


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, Value> members;

    members.insert({ "Minho", Value("Root", 0)});

    for(int i = 0; i < enroll.size(); i++)
    {
        if (referral[i] == "-")
            members.insert({ enroll[i], Value("Minho", 0) });
        else
            members.insert({ enroll[i], Value(referral[i], 0) });
    }

    for(int i = 0; i < seller.size(); i++)
    {
        auto pos = members.find(seller[i]);
        int money = amount[i] * 100;
        Value* v = &pos->second;

        while(v->getReferral() != "Root")
        {
	        if(money / 10 < 1)
	        {
                v->setMoney(v->getMoney() + money);
                break;
	        }
            else
            {
                v->setMoney(v->getMoney() + (money - (money / 10)));
                money /= 10;

                pos = members.find(v->getReferral());
                v = &pos->second;
            }
        }
    }

    for (string& s : enroll)
    {
        auto pos = members.find(s);
        answer.push_back(pos->second.getMoney());
    }

    return answer;
}
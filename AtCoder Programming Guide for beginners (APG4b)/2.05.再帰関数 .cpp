#include <bits/stdc++.h>
using namespace std;

// EX20 - 報告書の枚数
// x番の組織が親組織に提出する枚数を返す
// childrenは組織の関係を表す2次元配列(参照渡し)
int count_report_num(vector<vector<int>> &children, int x) {
  // (ここに追記して再帰関数を実装する)
  // ベースケース(子組織が存在するかを判定。子組織がなければ0)
  if(children.at(x).size() == 0){
    return 1;
  }

  // 再帰ステップ(子組織が存在しなくなるまで再帰して、報告書に加算する)
  int countHoukokusho = 0;//ロジックがおかしい一番最初のところからトレースする
  countHoukokusho++; //自組織文の報告書一枚加算
  for(int c:children.at(x)){
    countHoukokusho = countHoukokusho + count_report_num(children,c);
  }
  return countHoukokusho;
}

// これ以降の行は変更しなくてよい

int main() {
  int N;
  cin >> N;

  vector<int> p(N);  // 各組織の親組織を示す配列
  p.at(0) = -1;  // 0番組織の親組織は存在しないので-1を入れておく
  for (int i = 1; i < N; i++) {
    cin >> p.at(i);
  }

  // 組織の関係から2次元配列を作る
  vector<vector<int>> children(N);  // ある組織の子組織の番号一覧
  for (int i = 1; i < N; i++) {
    int parent = p.at(i);  // i番の親組織の番号
    children.at(parent).push_back(i);  // parentの子組織一覧にi番を追加
  }

  // 各組織について、答えを出力
  for (int i = 0; i < N; i++) {
    cout << count_report_num(children, i) << endl;
  }
}

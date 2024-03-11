#include "bits/stdc++.h"
using namespace std;

class Person {
public:
  double prob, underperform_prob, success_prob, failure_prob;
  Person(double p = 0, double up = 0, double sp = 0, double fp = 0)
      : prob(p), underperform_prob(up), success_prob(sp), failure_prob(fp) {}

  double successProbability() {
    return prob * success_prob + (1 - prob) * (1 - failure_prob);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Person alice(0.7, 0.3, 0.9, 0.6);
  Person bob(0.8, 0.2, 0.8, 0.95);

  if (alice.successProbability() > bob.successProbability())
    cout << "Alice\n";
  else if (alice.successProbability() < bob.successProbability())
    cout << "Bob\n";
  else
    cout << "Both candidate have same probability\n";
}

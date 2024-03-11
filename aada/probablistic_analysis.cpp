#include <iostream>
using namespace std;

double calculateOverallSuccessProbability(double probability,
                                          double successRate,
                                          double failureRate) {
  return probability * successRate + (1 - probability) * (1 - failureRate);
}

int main() {
  double probabilityAlice = 0.7;
  double probabilityUnderperformAlice = 1 - probabilityAlice;
  double successRateAlice = 0.9;
  double failureRateUnderperformAlice = 0.6;

  double probabilityBob = 0.8;
  double probabilityExceedBob = 1 - probabilityBob;
  double successRateBob = 0.8;
  double failureRateExceedBob = 0.95;

  double overallSuccessProbabilityAlice = calculateOverallSuccessProbability(
      probabilityAlice, successRateAlice, failureRateUnderperformAlice);
  double overallSuccessProbabilityBob = calculateOverallSuccessProbability(
      probabilityBob, successRateBob, failureRateExceedBob);

  // Output the results
  cout << "Overall Success Probability for Alice: "
       << overallSuccessProbabilityAlice << endl;
  cout << "Overall Success Probability for Bob: "
       << overallSuccessProbabilityBob << endl;

  if (overallSuccessProbabilityAlice > overallSuccessProbabilityBob) {
    cout << "Select Alice for the critical project." << endl;
  } else if (overallSuccessProbabilityAlice < overallSuccessProbabilityBob) {
    cout << "Select Bob for the critical project." << endl;
  } else {
    cout << "Both candidates have equal overall success probabilities. "
            "Consider other factors for the decision."
         << endl;
  }

  return 0;
}

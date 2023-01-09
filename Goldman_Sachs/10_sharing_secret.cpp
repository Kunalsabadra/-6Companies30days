/*
i-> i+delay(Acting as aspreader)

i-> i+forget(Forgetting the secret)

noofNewPeopleSharingSecret i-> dp[i-delay]
noofPeopleForgetting the secret on ith day i-> dp[i-forget]

noofpeoplesharingsecret = noofpeoplesharingsecret + noofNewPeopleSharingSecret - noofPeopleForgetting

T.C : O(n) 
S.C: O(N)   extra space for dp array
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
          
          vector<long> dp(n+1 , 0);
          long mod = 1e9+7;
          long PeopleSharingSecret = 0;
          long ans = 0;
          
          //day 1 only one person knows the secret
          dp[1] = 1;

          //i -> days
          for(int i=2; i<=n; i++){
               long noofNewPeopleSharingSecret = 0;
              if(i-delay > 0){
                   noofNewPeopleSharingSecret = dp[i-delay];
              }
              long noofPeopleForgettingSecret = 0;
              if(i - forget > 0)    noofPeopleForgettingSecret = dp[i-forget];
              PeopleSharingSecret += (noofNewPeopleSharingSecret - noofPeopleForgettingSecret + mod)%mod;
              
              //dp[i] => no of peoples who found secret on ith day
              dp[i] = PeopleSharingSecret;
          }
        
          for(int i=n-forget+1; i<=n; i++){
              ans = (ans+dp[i])%mod;
          }
          return (int)ans;
    }
};

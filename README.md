*Purpose* 

This project can be used to reproduce 2 login issues with Android using the EOS OSS plugin in UE 4.27.2. I was unable to reproduce the issues myself as I can't package this game for Anroid. However, several customers have reported the issue, so this should be reproducible using this very simple game. 

*Issues* 
1. Log in issue with browser staying open: https://eoshelp.epicgames.com/s/question/0D54z00007MN5jQCAT/unable-to-complete-login-on-quest-2?language=en_US
2. Log in issue where login fails due to Persistent Auth: https://eoshelp.epicgames.com/s/question/0D54z00007OpokqCAB/accountportal-method-does-not-work-at-all-on-android-if-any-persistent-auth-operations-are-performed-before-it?language=en_US

*How to* 
1. Package the game to run on Android. 
2. Using Android studio (https://docs.unrealengine.com/4.27/en-US/SharingAndReleasing/Mobile/Android/AndroidDebugging/) run the game. 
3. The game is a simple "Login" button. Click on the button. 
4. A browser page should open asking you to enter your Epic Account Credentials. Reach out to sebastienbergeron@improbable.io so he can add you to the application in the dev portal so you can have access. Alternatively, change the EOS OSS plugin settings to point to your own application. 
5. Once logged in the browser should close. Customers have reported that the browser redirects to the "login failed" page even though the login is succesfull. See the EOSHelp link under issue (1) above for details. 
6. For the 2nd issue, you will need to modify the UE OSS EOS plugin source code to add persistentauth. The customer in (2) detailed the steps in the EOSHelp post. 


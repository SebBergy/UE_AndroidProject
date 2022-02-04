// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineIdentityInterface.h"


void UMainMenu::Login()
{
    IOnlineSubsystem* Subsystem = Online::GetSubsystem(this->GetWorld());
    IOnlineIdentityPtr Identity = Subsystem->GetIdentityInterface();
    FOnlineAccountCredentials* Credentials = new FOnlineAccountCredentials("accountportal", "", "");
    UE_LOG(LogTemp, Warning, TEXT("Logging in..."));
    Identity->AddOnLoginCompleteDelegate_Handle(
        0,
        FOnLoginComplete::FDelegate::CreateUObject(
            this,
            &UMainMenu::HandleLoginComplete));
    Identity->Login(0, *Credentials);
}

void UMainMenu::HandleLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
    if (bWasSuccessful)
    {
        // Deregister the event handler.
        UE_LOG(LogTemp, Warning, TEXT("Login callback completed..."));
        IOnlineSubsystem* Subsystem = Online::GetSubsystem(this->GetWorld());
        IOnlineIdentityPtr Identity = Subsystem->GetIdentityInterface();
        Identity->ClearOnLoginCompleteDelegate_Handle(LocalUserNum, this->LoginDelegateHandle);
        this->LoginDelegateHandle.Reset();
        LoginCompleted(); //call blueprint callable event to open the level
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Event handle triggered, but login failed.")); 
    }
}


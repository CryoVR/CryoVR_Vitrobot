// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkReplayStreaming.h"
#include "Engine/GameInstance.h"
#include "VB_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SOMTEMPLATE_VR_API UVB_GameInstance : public UGameInstance
{
	GENERATED_BODY()

//public:
//	/** Start recording a replay from blueprint. ReplayName = Name of file on disk, FriendlyName = Name of replay in UI */
//	UFUNCTION(BlueprintCallable, Category = "Replays")
//		void StartRecordingReplayFromBP(FString ReplayName, FString FriendlyName);
//
//	/** Start recording a running replay and save it, from blueprint. */
//	UFUNCTION(BlueprintCallable, Category = "Replays")
//		void StopRecordingReplayFromBP();
//
//	/** Start playback for a previously recorded Replay, from blueprint */
//	UFUNCTION(BlueprintCallable, Category = "Replays")
//		void PlayReplayFromBP(FString ReplayName);
//
//	/** Start looking for/finding replays on the hard drive */
//	UFUNCTION(BlueprintCallable, Category = "Replays")
//		void FindReplays();
//
//	/** Apply a new custom name to the replay (for UI only) */
//	UFUNCTION(BlueprintCallable, Category = "Replays")
//		void RenameReplay(const FString &ReplayName, const FString &NewFriendlyReplayName);
//
//	/** Delete a previously recorded replay */
//	UFUNCTION(BlueprintCallable, Category = "Replays")
//		void DeleteReplay(const FString &ReplayName);
//
//	virtual void Init() override;
//
//private:
//
//	// for FindReplays() 
//	TSharedPtr<INetworkReplayStreamer> EnumerateStreamsPtr;
//	FOnEnumerateStreamsComplete OnEnumerateStreamsCompleteDelegate;
//
//	void OnEnumerateStreamsComplete(const TArray<FNetworkReplayStreamInfo>& StreamInfos);
//
//	// for DeleteReplays(..)
//	FOnDeleteFinishedStreamComplete OnDeleteFinishedStreamCompleteDelegate;
//
//	void OnDeleteFinishedStreamComplete(const bool bDeleteSucceeded);
//
//	/*USTRUCT(BlueprintType)
//		struct FS_ReplayInfo
//	{
//		GENERATED_USTRUCT_BODY()
//
//			UPROPERTY(BlueprintReadOnly)
//			FString ReplayName;
//
//		UPROPERTY(BlueprintReadOnly)
//			FString FriendlyName;
//
//		UPROPERTY(BlueprintReadOnly)
//			FDateTime Timestamp;
//
//		UPROPERTY(BlueprintReadOnly)
//			int32 LengthInMS;
//
//		UPROPERTY(BlueprintReadOnly)
//			bool bIsValid;
//
//		FS_ReplayInfo(FString NewName, FString NewFriendlyName, FDateTime NewTimestamp, int32 NewLengthInMS)
//		{
//			ReplayName = NewName;
//			FriendlyName = NewFriendlyName;
//			Timestamp = NewTimestamp;
//			LengthInMS = NewLengthInMS;
//			bIsValid = true;
//		}
//
//		FS_ReplayInfo()
//		{
//			ReplayName = "Replay";
//			FriendlyName = "Replay";
//			Timestamp = FDateTime::MinValue();
//			LengthInMS = 0;
//			bIsValid = false;
//		}
//	};*/
//
//protected:
//	UFUNCTION(BlueprintImplementableEvent, Category = "Replays")
//		void BP_OnFindReplaysComplete(const TArray<FS_ReplayInfo> &AllReplays);
};

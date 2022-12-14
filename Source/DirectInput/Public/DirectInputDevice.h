﻿/*
* Track Evolution
* Copyright (c) 2021-2022 Anders Dahnielson. All rights reserved.
*/

#pragma once

#include "DirectInput.h"

class FDirectInputDevice : public IDInputDevice
{
public:
	FDirectInputDevice(const TSharedRef<FGenericApplicationMessageHandler> &InMessageHandler);
	virtual ~FDirectInputDevice() override;
	/** Tick the interface (e.g. check for new controllers) */
	virtual void Tick(float DeltaTime) override;
	/** Poll for controller state and send events if needed */
	virtual void SendControllerEvents() override;
	/** Set which MessageHandler will get the events from SendControllerEvents. */
	virtual void SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler> &InMessageHandler) override;
	/** Exec handler to allow console commands to be passed through for debugging */
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	// IForceFeedbackSystem pass through functions
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &Values) override;
	
	TArray<FName> AxisNames;
	TArray<FName> ButtonNames;
	TArray<FName> PovNames;

	FName DirectInputInterfaceName;

private:
	float TimeSinceLastCheck;
};

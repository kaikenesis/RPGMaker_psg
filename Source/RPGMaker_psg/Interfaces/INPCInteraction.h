#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INPCInteraction.generated.h"

UINTERFACE(MinimalAPI)
class UINPCInteraction : public UInterface
{
	GENERATED_BODY()
};

class RPGMAKER_PSG_API IINPCInteraction
{
	GENERATED_BODY()

public:
	virtual void ActivateDialogue_Interface() = 0;
};

#include "FGGameplayDebuggerCategory.h"
#include "FG21_AI_Controller.h"

FFGGameplayDebuggerCategory::FFGGameplayDebuggerCategory()
{


}

TSharedRef<FGameplayDebuggerCategory> FFGGameplayDebuggerCategory::MakeInstance()
{

	return MakeShareable(new FFGGameplayDebuggerCategory());

}

void FFGGameplayDebuggerCategory::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	AFG21_AI_Controller* Controller = Cast<AFG21_AI_Controller>(DebugActor->GetInstigatorController());

	if (Controller == nullptr)
	{
		return;
	}

	DebugData.Distance = Controller->GetPlayerDistance();

}

void FFGGameplayDebuggerCategory::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext)
{
	CanvasContext.Printf(TEXT("{green} Distance to player:  %s"), *FString::SanitizeFloat(DebugData.Distance));
}

// MyButtonsWidget

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyButtonsWidget.generated.h"

/**
 *
 */
UCLASS()
class TESTTASK_API UMyButtonsWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual bool Initialize();


	UPROPERTY(meta = (BindWidget))
	class UTextBlock* OutputText;


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_1;

	UFUNCTION()
	void Button_1Clicked();

	void DisplaySelectedValue();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_2;

	UFUNCTION()
	void Button_2Clicked();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_3;

	UFUNCTION()
	void Button_3Clicked();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_4;

	UFUNCTION()
	void Button_4Clicked();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_5;

	UFUNCTION()
	void Button_5Clicked();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_6;

	UFUNCTION()
	void Button_6Clicked();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Update;

	UFUNCTION()
	void Button_UpdateClicked();
	
	void UpdateIndices(int32 Index);

private:

	UPROPERTY()
	class UDataHolder* DataHolder;
};

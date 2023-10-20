// MyButtonsWidget.cpp


#include "MyButtonsWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "DataHolder.h"

void UMyButtonsWidget::NativeConstruct()
{
    Super::NativeConstruct();

    DataHolder = NewObject<UDataHolder>(GetOwningPlayer());
    DataHolder->Init("");
    DataHolder->LoadData();
}

bool UMyButtonsWidget::Initialize()
{
	Super::Initialize();
    
	Button_1->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_1Clicked);
	Button_2->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_2Clicked);
	Button_3->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_3Clicked);
	Button_4->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_4Clicked);
	Button_5->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_5Clicked);
	Button_6->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_6Clicked);
	Button_Update->OnClicked.AddDynamic(this, &UMyButtonsWidget::Button_UpdateClicked);

	return true;
}

int32 SelectedRowIndex = -1; // Инициализация индекса выбранной строки
int32 SelectedColumnIndex = -1; // Инициализация индекса выбранного столбца
bool bRowSelected = false; // Флаг, указывающий, выбрана ли уже строка

void UMyButtonsWidget::DisplaySelectedValue()
{
	int32 Value = 0;

	if (DataHolder->GetValue(SelectedRowIndex, SelectedColumnIndex, Value))
	{
		FText NewText = FText::AsNumber(Value);
		OutputText->SetText(NewText);
	}

    // Сбросить выбор строки и столбца для следующей операции
    SelectedRowIndex = -1;
    SelectedColumnIndex = -1;
    bRowSelected = false;
}

void UMyButtonsWidget::Button_1Clicked()
{
	UpdateIndices(0);
}

void UMyButtonsWidget::Button_2Clicked()
{
	UpdateIndices(1);
}

void UMyButtonsWidget::Button_3Clicked()
{
	UpdateIndices(2);
}

void UMyButtonsWidget::Button_4Clicked()
{
	UpdateIndices(3);
}

void UMyButtonsWidget::Button_5Clicked()
{
	UpdateIndices(4);
}

void UMyButtonsWidget::Button_6Clicked()
{
	UpdateIndices(5);
}

void UMyButtonsWidget::Button_UpdateClicked()
{
	DataHolder->LoadData();

	SelectedRowIndex = -1;
	SelectedColumnIndex = -1;
	bRowSelected = false;
}

void UMyButtonsWidget::UpdateIndices(int32 Index)
{
	if (!bRowSelected) {
		SelectedRowIndex = Index;
		bRowSelected = true;
	}
	else {
		SelectedColumnIndex = Index;

		if (SelectedColumnIndex >= 0 && SelectedRowIndex >= 0)
		{
			DisplaySelectedValue();
		}
	}
}

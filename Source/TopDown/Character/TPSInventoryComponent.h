// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TopDown/FuncLibrary/Types.h"
#include "TPSInventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSwitchWeapon, FName, WeaponIdName, FAdditionalWeaponInfo, WeaponAdditionalInfo, int32, NewCurrentIndexWeapon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChange, EWeaponType, TypeAmmo, int32, Cout);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponAmmoAviable, EWeaponType, WeaponType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponAmmoEmpty, EWeaponType, WeaponType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponNotHaveRound, int32, IndexSlotWeapon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponHaveRound, int32, IndexSlotWeapon);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWN_API UTPSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTPSInventoryComponent();

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnSwitchWeapon OnSwitchWeapon;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	//Event on change ammo in slots by weaponType
	FOnAmmoChange OnAmmoChange;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnWeaponAmmoAviable OnWeaponAmmoAviable;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnWeaponAmmoEmpty OnWeaponAmmoEmpty;

	//Event current weapon not have additional_Rounds 
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnWeaponNotHaveRound OnWeaponNotHaveRound;
	//Event current weapon have additional_Rounds 
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnWeaponHaveRound OnWeaponHaveRound;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapons")
		TArray<FWeaponSlot> WeaponSlots;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapons")
		TArray<FAmmoSlot> AmmoSlots;

	int32 MaxSlotsWeapon = 0;

	bool SwitchWeaponToIndex(int32 ChangeToIndex, int32 OldIndex, FAdditionalWeaponInfo OldInfo);
	bool SwitchWeaponToIndexByNextPreviosIndex(int32 ChangeToIndex, int32 OldIndex, FAdditionalWeaponInfo OldInfo, bool bIsForward);
	bool SwitchWeaponByIndex(int32 IndexWeaponToChange, int32 PreviosIndex, FAdditionalWeaponInfo PreviosWeaponInfo);
	bool GetWeaponTypeByNameWeapon(FName IdWeaponName, EWeaponType& WeaponType);
	bool GetWeaponTypeByIndexSlot(int32 IndexSlot, EWeaponType& WeaponType);
	FName GetWeaponNameBySlotIndex(int32 IndexSlot);
	FAdditionalWeaponInfo GetAdditionalInfoWeapon(int32 IndexWeapon);
	int32 GetWeaponIndexSlotByName(FName IdWeaponName);
	void SetAdditionalInfoWeapon(int32 IndexWeapon, FAdditionalWeaponInfo NewInfo);
	
	UFUNCTION(BlueprintCallable)
	void AmmoSlotChangeValue(EWeaponType TypeWeapon, int32 CoutChangeAmmo);
	bool CheckAmmoForWeapon(EWeaponType TypeWeapon, int8& AvailableAmmoForWeapon);

	UFUNCTION(BlueprintCallable, Category = "Interface")
	void DropWeaponByIndex(int32 ByIndex, FDropItem& DropItemInfo);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "GameFramework/Actor.h"

void UMyBlueprintFunctionLibrary::SortActorsByDist(FVector Location, const TArray<AActor*>& InArr, TArray<AActor*>& OutArr, bool Inverse /*= false*/)
{
	OutArr = InArr.FilterByPredicate([](AActor* A) { return IsValid(A); });
	auto Pred = [Location, Inverse](AActor* A, AActor* B)
	{
		bool ACloser = FVector::DistSquared(Location, A->GetActorLocation()) < FVector::DistSquared(Location, B->GetActorLocation());
		return Inverse ? !ACloser : ACloser;
	};
	Algo::Sort(OutArr, Pred);
}

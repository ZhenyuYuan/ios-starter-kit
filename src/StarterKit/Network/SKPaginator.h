//
// Created by Hammer on 1/18/16.
// Copyright (c) 2016 奇迹空间. All rights reserved.
//

#import <PromiseKit/PromiseKit.h>

@protocol SKPaginatorDelegate <NSObject>
@required
- (void)networkOnStart:(BOOL)isRefresh;
- (AnyPromise *)paginate:(NSDictionary *)parameters;
@end

@interface SKPaginator : NSObject

@property(nonatomic, assign, readonly) BOOL hasDataLoaded;
@property(nonatomic, assign, getter=isRefresh) BOOL refresh;
@property(nonatomic, assign, getter=isLoading) BOOL loading;

@property(nonatomic, weak) id <SKPaginatorDelegate> delegate;
- (AnyPromise *)refresh;
- (AnyPromise *)loadMore;
@end

@interface SKPagedPaginator : SKPaginator
@property(nonatomic, assign, readonly) NSUInteger firstPage;
@property(nonatomic, assign, readonly) NSUInteger nextPage;
@property(nonatomic, assign, readonly) NSUInteger pageSize;
@end

@interface SKKeyPaginator : SKPaginator

- (instancetype)initWithEntityName:(NSString *)entityName;

@end
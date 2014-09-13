//
//  MainBottomView.h
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MainBottomViewDelegate <NSObject>
- (void) mainBottomViewWillShow;
- (void) mainBottomViewDidShow;
@end

@interface MainBottomView : UIView

@property (weak, nonatomic) IBOutlet UIView *topView;
// 刷新
//- (void) update:(Intersections *)interaction;


@end

//
//  ZTBriefBottomView.m
//  ZTJTApp
//
//  Created by Perry on 14-7-19.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "ZTBriefBottomView.h"

@interface ZTBriefBottomView ()
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UIButton *linkButton;

@end

@implementation ZTBriefBottomView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

#pragma mark - 重写属性方法
- (void) setTitle:(NSString *)title
{
    _title = title;
    
    self.titleLabel.text = title;
}

- (void) setLinked:(BOOL)linked
{
    if (_linked != linked)
    {
        _linked = linked;
        
        if (_linked)
        {
            [self.linkButton setTitleColor:[UIColor greenColor] forState:UIControlStateNormal];
            [self.linkButton setTitle:@"已连接" forState:UIControlStateNormal];
        }
        else
        {
            [self.linkButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateNormal];
            [self.linkButton setTitle:@"未连接" forState:UIControlStateNormal];
        }
        
    }
    
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

#pragma mark - 事件相应
- (IBAction)doDetail:(id)sender {
}

@end

//
//  TimeSetTableViewController.m
//  ZTJTApp
//
//  Created by Perry on 14-9-13.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "TimeSetTableViewController.h"
#import "InputCell.h"
#import "NSDate+Ext.h"
#import "TimeSetFooterView.h"
#import "TimeSetHeaderView.h"

#define kTimeSetTime @"time"
#define kTimeSetDayOfWeek @"dayofweek"

@interface TimeSetTableViewController ()
{
    Crossing *_crossing;
    DEVICETIME _deviceTime;
    DEVICETIME _newDeviceTime;
}


@property (weak, nonatomic) NSTimer *timer;

@property (weak, nonatomic) TimeSetHeaderView *headerView;

@end


@implementation TimeSetTableViewController

- (IBAction) save:(id)sender
{
    
}


- (IBAction) synToPhoneTime:(id)sender
{
    
}

- (void) timerFired:(NSTimer *)timer
{
    self.headerView.textLabel.text = [NSString stringWithFormat:@"当前时间:%@", [[NSDate date] stringFormat2] ];
}

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
        _crossing = Area::sharedInstance()->CurrentCrossing();
        _deviceTime = _crossing->DeviceTime();
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"编辑时钟";
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:@"保存" style:UIBarButtonItemStyleBordered target:self action:@selector(save:)];
    self.navigationItem.rightBarButtonItem = item;
    
    self.timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(timerFired:) userInfo:nil repeats:YES];
    
    // 异步读取时钟
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) dealloc
{
    [self.timer invalidate];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return 2;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    /*
    InputCell *cell = [tableView dequeueReusableCellWithIdentifier:@"InputCell" forIndexPath:indexPath];
    cell.textField.enabled = NO;
    // Configure the cell...
    switch (indexPath.row)
    {
        case 0:
            cell.titleLabel.text = @"时间";
            cell.textField.text = [self.date stringFormat1];
            break;
        case 1:
            cell.titleLabel.text = @"今天是";
            cell.textField.text = @"星期四";
        default:
            break;
    }
    */
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:nil];
    switch (indexPath.row)
    {
        case 0:
            cell.textLabel.text = @"设备时间";
            cell.detailTextLabel.text = [[NSDate date] stringFormat1];
            break;
        case 1:
            cell.textLabel.text = @"设备星期";
            cell.detailTextLabel.text = @"星期四";
        default:
            break;
    }
    return cell;
}


- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 35;
}


- (UIView *) tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    TimeSetHeaderView *headerView = nil;
    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"TimeSetHeaderView" owner:nil options:nil];
    
    headerView = [objs firstObject];
    headerView.textLabel.text = [NSString stringWithFormat:@"当前时间:%@", [[NSDate date] stringFormat2]];
    headerView.backgroundColor = [UIColor clearColor];
    
    self.headerView = headerView;
    
    return headerView;
}

//- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
//{
//    NSString *rttitle = nil;
//    switch (section)
//    {
//        case 0:
//        {
//            rttitle = [[NSDate date] stringFormat2];
//        }
//            
//            break;
//            
//        default:
//            break;
//    }
//    
//    return rttitle;
//}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 44;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    TimeSetFooterView *footerView = nil;
    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"TimeSetFooterView" owner:nil options:nil];
    
    footerView = [objs firstObject];
    [footerView.phoneTimeButton addTarget:self action:@selector(synToPhoneTime:) forControlEvents:UIControlEventTouchUpInside];
    [footerView.doneButton addTarget:self action:@selector(save:) forControlEvents:UIControlEventTouchUpInside];
    footerView.backgroundColor = [UIColor clearColor];
    
    return footerView;
}


@end

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

#define kTimeSetTime @"time"
#define kTimeSetDayOfWeek @"dayofweek"

@interface TimeSetTableViewController ()
@property (strong, nonatomic) NSDate *date;
@property (assign, nonatomic) NSInteger dayOfWeek;   //星期几 从0~6
@end

@implementation TimeSetTableViewController

- (IBAction) save:(id)sender
{
    
}



- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
        self.date = [NSDate date];
        _dayOfWeek = 3;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"编辑时钟";
    
    //[self.tableView registerNib:[UINib nibWithNibName:@"InputCell" bundle:nil] forCellReuseIdentifier:@"InputCell"];
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:@"保存" style:UIBarButtonItemStyleBordered target:self action:@selector(save:)];
    self.navigationItem.rightBarButtonItem = item;
    // 异步读取时钟
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
            cell.textLabel.text = @"时间";
            cell.detailTextLabel.text = [self.date stringFormat1];
            break;
        case 1:
            cell.textLabel.text = @"今天是";
            cell.detailTextLabel.text = @"星期四";
        default:
            break;
    }
    return cell;
}


/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

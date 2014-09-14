//
//  CrossingProfileTableViewController.m
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "CrossingProfileTableViewController.h"
#import "InputCell.h"
#import "IPCell.h"
#include <vector>


using namespace std;

@interface CrossingProfileTableViewController ()
{
    vector< pair<ZT::Crossing::CrossingRunMode, string> > _runModes;
    Crossing *_crossing;
}

@end

@implementation CrossingProfileTableViewController

#pragma mark - Private


- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
        _crossing = Area::sharedInstance()->CurrentCrossing();
        
        string str = _crossing->RunModeDescription(ZT::Crossing::CrossingRunModeRunMonitor);
        _runModes = _crossing->GetRunModes();
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
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
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    switch (section)
    {
        case 0:
            return 3;
        case 1:
            return 1;
        default:
            return 1;
            break;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    
    switch (indexPath.section)
    {
        case 0:         // 路口名称与运行模式
        {
            switch (indexPath.row)
            {
                case 0: // 路口名
                {
                    CGRect textFieldRect = CGRectMake(62.0, 0.0f, 215.0f, 31.0f);
                    UITextField *theTextField = [[UITextField alloc] initWithFrame:textFieldRect];
                    theTextField.contentVerticalAlignment= UIControlContentVerticalAlignmentCenter;
                    theTextField.keyboardType = UIKeyboardTypeDefault;
                    theTextField.returnKeyType = UIReturnKeyDone;
                    theTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
                    //theTextField.tag = row;
                    theTextField.delegate = self;
                    
                    cell.textLabel.text = @"路口名称";
                    theTextField.text = OS2SS(&(_crossing->Name()));
                    cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    cell.accessoryView = theTextField;
                    
                    return cell;
                }
                case 1: // 路口编号
                {
                    CGRect textFieldRect = CGRectMake(62.0, 0.0f, 215.0f, 31.0f);
                    UITextField *theTextField = [[UITextField alloc] initWithFrame:textFieldRect];
                    theTextField.contentVerticalAlignment= UIControlContentVerticalAlignmentCenter;
                    theTextField.keyboardType = UIKeyboardTypeNumberPad;
                    theTextField.returnKeyType = UIReturnKeyDone;
                    theTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
                    //theTextField.tag = row;
                    theTextField.delegate = self;
                    
                    cell.accessoryView = theTextField;
                    cell.textLabel.text = @"路口编号";
                    theTextField.text = [NSString stringWithFormat:@"%d", _crossing->No()];
                    cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                case 2: // 运行模式
                {
                    cell.textLabel.text = @"运行模式";
                    string runmodestr = _crossing->RunModeString();
                    cell.detailTextLabel.text = OS2SS(&runmodestr);
                    //cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                default:
                    return nil;
            }
        }
            break;
        case 1:
        {
            switch (indexPath.row)
            {
                case 0: // IP地址
                {
                    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"IPCell" owner:nil options:nil];
                    
                    IPCell *cell = (IPCell *)[objs firstObject];
                    cell.titleLabel.text = @"IP地址";
                    cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                default:
                    break;
            }
        }
        default:
            break;
    }
    
    return nil;
}

/*
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch (indexPath.section)
    {
        case 0:         // 路口名称与运行模式
        {
            switch (indexPath.row)
            {
                case 0: // 路口名
                {
                    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"InputCell" owner:nil options:nil];
                    
                    InputCell *cell = (InputCell *)[objs firstObject];
                    cell.titleLabel.text = @"路口名称";
                    cell.textField.keyboardType = UIKeyboardTypeDefault;
                    cell.textField.text = OS2SS(&(_crossing->Name()));
                    cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                case 1: // 路口编号
                {
                    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"InputCell" owner:nil options:nil];
                    //路口名称
                    InputCell *cell = (InputCell *)[objs firstObject];
                    cell.titleLabel.text = @"路口编号";
                    cell.textField.keyboardType = UIKeyboardTypeNumberPad;
                    cell.textField.text = [NSString stringWithFormat:@"%d", _crossing->No()];
                    cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                case 2: // 运行模式
                {
                    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"InputCell" owner:nil options:nil];
                    //路口名称
                    InputCell *cell = (InputCell *)[objs firstObject];
                    cell.titleLabel.text = @"运行模式";
                    string runmodestr = _crossing->RunModeString();
                    cell.textField.text = OS2SS(&runmodestr);
                    cell.textField.enabled = NO;
                    //cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                default:
                    return nil;
            }
        }
            break;
        case 1:
        {
            switch (indexPath.row)
            {
                case 0: // IP地址
                {
                    NSArray *objs = [[NSBundle mainBundle] loadNibNamed:@"IPCell" owner:nil options:nil];
                    
                    IPCell *cell = (IPCell *)[objs firstObject];
                    cell.titleLabel.text = @"IP地址";
                    cell.selectionStyle = UITableViewCellSelectionStyleNone;
                    
                    return cell;
                }
                default:
                    break;
            }
        }
        default:
            break;
    }
    
    return nil;
}
*/

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

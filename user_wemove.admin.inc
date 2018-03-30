<?php

function user_wemove_menu() {

  $items['admin/config/people/user_wemove'] = array(
    'title' => t('WEMOVE - YouMove User'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('user_wemove_admin_settings_form'),
    'access arguments' => array('administer site configuration'),
    'type' => MENU_NORMAL_ITEM,
    'file' =>'user_wemove.admin.inc', );

  return $items;
}



function user_wemove_admin_settings_form($form, &$form_state) {

  $form['ymu_user_role_name'] = array(
    '#type' => 'textfield',
    '#title' => t('YouMove user role name'),
    '#default_value' => variable_get('user_wemove__ymu_user_role_name'),
    '#required' => TRUE,
  );

  $form['#submit'][] = '_ymu_admin_settings_submit';

  return system_settings_form($form);
}

function _ymu_admin_settings_submit($form, $form_state) {
  variable_set('user_wemove__ymu_user_role_name',$form_state['values']['ymu_user_role_name']);
}

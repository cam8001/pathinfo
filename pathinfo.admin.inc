<?php
/**
 * @file
 *   Administration forms for PathInfo.
 */

/**
 * Form constructor.
 */
function pathinfo_config_form(&$form, $form_state) {
  
  $form = array(
    '#tree' => TRUE,
  );

  $form['show_pathinfo'] = array(
    '#type' => 'checkbox',
    '#title' => 
  );

  $form['link_functions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link functions to their documentation on ')
  )

  return system_settings_form($form);
}
<?php
/**
 * @file
 * Administration forms for PathInfo.
 */

/**
 * Form constructor.
 */
function pathinfo_config_form($form, &$form_state) {

  $form['pathinfo_footer_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Path Info details in page footer.'),
    '#default_value' => variable_get('pathinfo_footer_display', FALSE),
  );

  $t_arguments = array(
    '!drupalcontrib' => l(
      t('DrupalContrib'),
      'http://drupalcontrib.org/',
      array('external' => TRUE)
    ),
  );

  $form['pathinfo_link_functions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link functions to their documentation on !drupalcontrib', $t_arguments),
    '#default_value' => variable_get('pathinfo_link_functions', FALSE),
  );

  return system_settings_form($form);
}

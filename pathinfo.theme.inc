<?php
/**
 * @file
 * Contains theme implementations for pathinfo.module.
 */

/**
 * Returns a div with a simple string describing the current path.
 *
 * @param array $variables
 *   An associative array containing:
 *   - path: System path to url.
 *   - function: The function that serves the path.
 *   - arguments: Array of arguments passed to the function serving the path.
 *   - module: The module that contains the function.
 *   - filepath: Relative ath to the file that implements the function.
 *   - filepath_full: The full path to the file that contains the function.
 *   - line: The line the function is implemented on.
 *   - is_form: Whether or not the function is a form constructor.
 *   - is_core: Whether or not this module is in Drupal core.
 *
 * @ingroup themeable
 */
function theme_pathinfo_served_by($variables) {
  // Link functions to their API docs if required.
  $function = $variables['function'];
  if ($variables['is_core'] && variable_get('pathinfo_link_functions', TRUE)) {
    $args = array(
      'function' => $variables['function'],
      'filepath' => $variables['filepath'],
    );
    $function = theme('pathinfo_core_api_link', $args);
  }
  // Convert variable names to t() arguments.
  $t_arguments = array(
    '@path' => $variables['path'],
    '!function' => $function,
    '@arguments' => implode(',', $variables['arguments']),
    '@module' => $variables['module'],
    '@implemented_in' => $variables['filepath_full'],
    '@line' => $variables['line'],
  );
  $message = '@path is served by !function';
  if ($variables['is_form']) {
    $message .= ' (form definition)';
  }
  $message .= ', implemented by @module in @implemented_in at line @line';
  if ($variables['arguments']) {
    $message .= ' with arguments: @arguments';
  }

  $message = t_safe($message, $t_arguments);
  $output = '<div class="pathinfo pathinfo-served-by">';
  $output .= l(t('PathInfo: '), 'admin/config/pathinfo/config');
  $output .= $message;
  $output .= '</div>';

  return $output;
}

/**
 * Generates a link to Drupal API documentation.
 *
 * @param array $variables
 *   An associative array containing:
 *   - function: The name of the function to link to.
 *   - filepath: The full relative path to the file the function is in.
 *
 * @ingroup themeable
 */
function theme_pathinfo_core_api_link($variables) {
  // Drupal API functions have the file path in the url.
  $url = 'http://api.drupal.org/api/drupal/%s/function/%s/7';
  // Urls in API module are encoded in a funny way.
  $url_filepath = str_replace('/', '%21', $variables['filepath']);
  $url = sprintf($url, $url_filepath, $variables['function']);

  // No t() here because we don't want to change function names!
  return l(
    check_plain($variables['function']),
    filter_xss($url),
    array(
      'options' => array(
        'external' => TRUE,
      )
    )
  );
}

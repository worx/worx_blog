<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Worx: Blog node templates"),
  'description' => t('Control access by Blog node template settings.'),
  'callback' => 'worx_blog_node_template_access_check',
  'settings form' => 'worx_blog_node_template_access_settings',
  'settings form submit' => 'worx_blog_node_template_access_settings_submit',
  'summary' => 'worx_blog_node_template_access_summary',
);

/**
 * Settings form for the 'Worx: Blog node templates' access plugin worx_blog_node_template_access_settings.
 */
function worx_blog_node_template_access_settings(&$form, &$form_state, $conf) {
  $form['settings']['worx_blog_node_template'] = array(
    '#type' => 'select',
    '#title' => t('Blog\'s Node Template'),
    '#options' => array(
      'worx_blog_node_template_one' => t('Template One'),
      'worx_blog_node_template_two' => t('Template Two'),
      'worx_blog_node_template_three' => t('Template Three'),
    ),
    '#required' => TRUE,
    '#default_value' => $conf['worx_blog_node_template'],
  );
  return $form;
}

/**
 * Compress the node_types allowed to the minimum.
 */
function worx_blog_node_template_access_settings_submit(&$form, &$form_state) {
}

/**
 * Check for access.
 */
function worx_blog_node_template_access_check($conf, $context) {
  return $conf['worx_blog_node_template'] == variable_get('worx_blog_node_template', 'worx_blog_node_template_one');
}

/**
 * Provide a summary description based upon the checked node_types.
 */
function worx_blog_node_template_access_summary($conf, $context) {
  if ($conf['worx_blog_node_template'] == 'worx_blog_node_template_one') {
    $template = t('Template One');
  }
  elseif ($conf['worx_blog_node_template'] == 'worx_blog_node_template_two') {
    $template = t('Template Two');
  }
  else {
    $template = t('Template Three');
  }
  return t('Display template is set to: ' . $template);
}

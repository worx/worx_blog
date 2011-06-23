<?php

/**
 * Define the function worx_blog_admin_settings_form().
 *
 * This function will create the admin settings page.
 */
function worx_blog_admin_settings_form() {
  $form = array();

  $form['blog_list'] = array(
    '#type' => 'select',
    '#title' => t('Blog\'s List Template'),
    '#options' => array(
      'worx_blog_list_template_one' => t('Template One'),
      'worx_blog_list_template_two' => t('Template Two'),
      'worx_blog_list_template_three' => t('Template Three'),
    ),
    '#default_value' => variable_get('worx_blog_list_template', 'worx_blog_list_template_one'),
    '#required' => TRUE,
  );
  $form['blog_node'] = array(
    '#type' => 'select',
    '#title' => t('Blog\'s Node Template'),
    '#options' => array(
      'worx_blog_node_template_one' => t('Template One'),
      'worx_blog_node_template_two' => t('Template Two'),
      'worx_blog_node_template_three' => t('Template Three'),
    ),
    '#default_value' => variable_get('worx_blog_node_template', 'worx_blog_node_template_one'),
    '#required' => TRUE,
  );
  $form['blog_vocab'] = array(
    '#type' => 'select',
    '#title' => t('Blog\'s Vocab Template'),
    '#options' => array(
      'worx_blog_vocab_template_one' => t('Template One'),
      'worx_blog_vocab_template_two' => t('Template Two'),
      'worx_blog_vocab_template_three' => t('Template Three'),
    ),
    '#default_value' => variable_get('worx_blog_vocab_template', 'worx_blog_vocab_template_one'),
    '#required' => TRUE,
  );
  $form['blog_read_all_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Blog\'s Block\'s Read All Link Path'),
    '#default_value' => variable_get('worx_blog_read_all_path', ''),
  );
  $form['blog_read_all_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Blog\'s Block\'s Read All Link Text'),
    '#default_value' => variable_get('worx_blog_read_all_text', ''),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('worx_blog_admin_settings_form_submit'),
  );

  return $form;
}

/*
 * Define the function worx_blog_admin_settings_form_submit().
 *
 * This function will save the admin settings page.
 */
function worx_blog_admin_settings_form_submit($form, &$form_state) {
  variable_set('worx_blog_list_template', $form_state['values']['blog_list']);
  variable_set('worx_blog_node_template', $form_state['values']['blog_node']);
  variable_set('worx_blog_vocab_template', $form_state['values']['blog_vocab']);
  variable_set('worx_blog_read_all_path', $form_state['values']['blog_read_all_path']);
  variable_set('worx_blog_read_all_text', $form_state['values']['blog_read_all_text']);
  drupal_set_message('Configuration has been saved.');
}
